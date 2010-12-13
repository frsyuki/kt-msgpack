#include <ktplugserv.h>
#include "gen/server.hpp"
#include <stdarg.h>
#include <sys/time.h>

#define MODNAME "msgpack-rpc"
#define LOG_PREFIX MODNAME ": "

namespace {

namespace kc = kyotocabinet;
namespace kt = kyototycoon;

namespace rpc = msgpack::rpc;

class MessagePackServer : public kt::PluggableServer, public KyotoTyrantService::server {
public:
	MessagePackServer() { }
	~MessagePackServer() { }

private:
	typedef kt::ThreadedServer::Logger Logger;

private:
	static void log(Logger* logger, Logger::Kind kind, const char* format, ...) {
		char buf[1024];
		va_list ap;
		va_start(ap, format);
		int len = vsnprintf(buf, sizeof(buf)-1, format, ap);
		va_end(ap);
		buf[len] = '\0';
		logger->log(kind, buf);
	}

public:
	void configure(kt::TimedDB* dbary, size_t dbnum,
			Logger* logger, uint32_t logkinds,
			const char* expr)
	{
		m_cfg.parse(logger, expr);
		m_dbary = dbary;
		m_dbnum = dbnum;

		m_logger = logger;
		log(m_logger, Logger::SYSTEM, LOG_PREFIX "configured: expr=%s", expr);
		log(m_logger, Logger::DEBUG, LOG_PREFIX "  host=%s", m_cfg.host.c_str());
		log(m_logger, Logger::DEBUG, LOG_PREFIX "  port=%d", m_cfg.port);
		log(m_logger, Logger::DEBUG, LOG_PREFIX "  thread=%d", m_cfg.thread);
	}

	bool start()
	try {
		gettimeofday(&m_start_time, NULL);

		instance.listen(m_cfg.host, m_cfg.port);

		instance.get_loop()->start(m_cfg.thread);

		return true;

	} catch (std::exception& e) {
		log(m_logger, Logger::ERROR, LOG_PREFIX "listen failed: %s", e.what());
		return false;
	}

	bool stop() {
		instance.get_loop()->end();
		instance.close();
		return true;
	}

	bool finish() {
		instance.get_loop()->join();
		return true;
	}

private:
	class Config {
	public:
		Config() :
			host("0.0.0.0"),
			port(0),
			thread(8)
		{ }

	private:
		void option(Logger* logger,
				const std::string& key, const std::string& value)
		{
			if(key == "host") {
				host = value;
			} else if(key == "port") {
				port = kc::atoi(value.c_str());
			} else if(key == "thread") {
				thread = kc::atoi(value.c_str());
			} else {
				log(logger, Logger::SYSTEM,
						LOG_PREFIX "unknown option: %s", key.c_str());
			}
		}

	public:
		void parse(Logger* logger, const char* expr) {
			std::vector<std::string> elems;
			kc::strsplit(expr, '#', &elems);
			for(std::vector<std::string>::const_iterator it(elems.begin()),
					it_end(elems.end()); it != it_end; ++it) {
				size_t poseq = it->find('=');
				if(poseq != std::string::npos) {
					option(logger, it->substr(0,poseq), it->substr(poseq+1));
				} else {
					option(logger, *it, "");
				}
			}
		}

	public:
		std::string host;
		uint16_t port;
		uint16_t thread;
	private:
		Logger* m_logger;
	};

	Config m_cfg;
	Logger* m_logger;
	kt::TimedDB* m_dbary;
	size_t m_dbnum;

	struct timeval m_start_time;

private:
	void count(msgpack::rpc::request::type<uint64_t> req, KyotoTyrantService::count& params) {
		req.result(get_db()->count());
	}

	void size(msgpack::rpc::request::type<uint64_t> req, KyotoTyrantService::size& params) {
		req.result(get_db()->size());
	}

	void set(msgpack::rpc::request::type<void> req, KyotoTyrantService::set& params) {
		bool success = get_db()->set(params.key.ptr, params.key.size,
				params.value.ptr, params.value.size, params.xt);
		if(!success) {
			throw_error("set failed");
		}
		req.result();
	}

	void add(msgpack::rpc::request::type<bool> req, KyotoTyrantService::add& params) {
		bool success = get_db()->add(params.key.ptr, params.key.size,
				params.value.ptr, params.value.size, params.xt);
		req.result(success);
	}

	void replace(msgpack::rpc::request::type<bool> req, KyotoTyrantService::replace& params) {
		bool success = get_db()->replace(params.key.ptr, params.key.size,
				params.value.ptr, params.value.size, params.xt);
		req.result(success);
	}

	void append(msgpack::rpc::request::type<void> req, KyotoTyrantService::append& params) {
		bool success = get_db()->append(params.key.ptr, params.key.size,
				params.value.ptr, params.value.size, params.xt);
		if(!success) {
			throw_error("append failed");
		}
		req.result();
	}

	void cas(msgpack::rpc::request::type<bool> req, KyotoTyrantService::cas& params) {
		bool success = get_db()->cas(params.key.ptr, params.key.size,
				params.ovalue.ptr, params.ovalue.size,
				params.nvalue.ptr, params.nvalue.size,
				params.xt);
		req.result(success);
	}

	void remove(msgpack::rpc::request::type<bool> req, KyotoTyrantService::remove& params) {
		bool success = get_db()->remove(params.key.ptr, params.key.size);
		req.result(success);
	}

	void get(msgpack::rpc::request::type<msgpack::type::raw_ref> req, KyotoTyrantService::get& params) {
		size_t vsiz;
		char* vbuf = get_db()->get(params.key.ptr, params.key.size, &vsiz);
		if(vbuf == NULL) {
			req.result_nil();
		} else {
			req.zone()->push_finalizer(&::free, vbuf);
			req.result(msgpack::type::raw_ref(vbuf, vsiz));
		}
	}

	void match_prefix(msgpack::rpc::request::type<std::vector<msgpack::type::raw_ref> > req, KyotoTyrantService::match_prefix& params) {
		std::vector<std::string>* strvec = req.zone()->allocate<std::vector<std::string> >();
		std::string prefix(params.prefix.ptr, params.prefix.size);
		if(get_db()->match_prefix(prefix, strvec, params.max) < 0) {
			throw_error("match_prefix failed");
		}

		std::vector<msgpack::type::raw_ref> refvec;
		string_vec_to_raw_ref_vec_nocopy(strvec, &refvec);
		req.result(refvec);
	}

	void match_regex(msgpack::rpc::request::type<std::vector<msgpack::type::raw_ref> > req, KyotoTyrantService::match_regex& params) {
		std::vector<std::string>* strvec = req.zone()->allocate<std::vector<std::string> >();
		std::string regex(params.regex.ptr, params.regex.size);
		if(get_db()->match_regex(regex, strvec, params.max) < 0) {
			throw_error("match_regex failed");
		}

		std::vector<msgpack::type::raw_ref> refvec;
		string_vec_to_raw_ref_vec_nocopy(strvec, &refvec);
		req.result(refvec);
	}

	void uptime(msgpack::rpc::request::type<double> req, KyotoTyrantService::uptime& params) {
		struct timeval now;
		gettimeofday(&now, NULL);
		struct timeval t;
		timersub(&now, &m_start_time, &t);
		double sec = t.tv_sec + (double)t.tv_usec*1e-6;
		req.result(sec);
	}


private:
	kt::TimedDB* get_db() {
		return &m_dbary[0];
	}

	void throw_error(const std::string& msg) {
		throw_error(msg, get_db()->error());
	}

	void throw_error(const std::string& msg, const kc::BasicDB::Error& err) {
		std::ostringstream s;
		s << msg;
		s << ": " << err.message();
		s << " (" << kc::BasicDB::Error::codename(err.code()) << ")";
		throw std::runtime_error(s.str());
	}

	void string_vec_to_raw_ref_vec_nocopy(
			const std::vector<std::string>* src,
			std::vector<msgpack::type::raw_ref>* dst) {
		for(std::vector<std::string>::const_iterator it(src->begin()),
				it_end(src->end()); it != it_end; ++it) {
			dst->push_back(msgpack::type::raw_ref(it->data(), it->size()));
		}
	}

private:
	MessagePackServer(const MessagePackServer&);
};

}  // noname namespace


extern "C"
void* ktservinit(void) {
	return new MessagePackServer();
}

