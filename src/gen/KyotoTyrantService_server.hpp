#ifndef MPRPC_KyotoTyrantService_server_0c363f6a_HPP__
#define MPRPC_KyotoTyrantService_server_0c363f6a_HPP__

#include "KyotoTyrantService.hpp"


namespace KyotoTyrantService {


class server : public msgpack::rpc::server::base {
public:
	server(msgpack::rpc::loop lo = msgpack::rpc::loop()) :
		msgpack::rpc::server::base(lo) { }

	virtual ~server() { }

	void dispatch(msgpack::rpc::request req);

private:
	class dispatch_table {
	public:
		dispatch_table();
		~dispatch_table();
		void* pimpl;
	};

	static dispatch_table s_dispatch_table;
	friend class dispatch_table;

public:
	virtual void count(msgpack::rpc::request::type<uint64_t>, KyotoTyrantService::count&) = 0;
	virtual void size(msgpack::rpc::request::type<uint64_t>, KyotoTyrantService::size&) = 0;
	virtual void set(msgpack::rpc::request::type<void>, KyotoTyrantService::set&) = 0;
	virtual void add(msgpack::rpc::request::type<bool>, KyotoTyrantService::add&) = 0;
	virtual void replace(msgpack::rpc::request::type<bool>, KyotoTyrantService::replace&) = 0;
	virtual void append(msgpack::rpc::request::type<void>, KyotoTyrantService::append&) = 0;
	virtual void cas(msgpack::rpc::request::type<bool>, KyotoTyrantService::cas&) = 0;
	virtual void remove(msgpack::rpc::request::type<bool>, KyotoTyrantService::remove&) = 0;
	virtual void get(msgpack::rpc::request::type<msgpack::type::raw_ref>, KyotoTyrantService::get&) = 0;
	virtual void match_prefix(msgpack::rpc::request::type<std::vector<msgpack::type::raw_ref> >, KyotoTyrantService::match_prefix&) = 0;
	virtual void match_regex(msgpack::rpc::request::type<std::vector<msgpack::type::raw_ref> >, KyotoTyrantService::match_regex&) = 0;
	virtual void uptime(msgpack::rpc::request::type<double>, KyotoTyrantService::uptime&) = 0;
};


}  // namespace KyotoTyrantService


/*
void KyotoTyrantService::server::count(msgpack::rpc::request::type<uint64_t> req, KyotoTyrantService::count& params)
void KyotoTyrantService::server::size(msgpack::rpc::request::type<uint64_t> req, KyotoTyrantService::size& params)
void KyotoTyrantService::server::set(msgpack::rpc::request::type<void> req, KyotoTyrantService::set& params)
void KyotoTyrantService::server::add(msgpack::rpc::request::type<bool> req, KyotoTyrantService::add& params)
void KyotoTyrantService::server::replace(msgpack::rpc::request::type<bool> req, KyotoTyrantService::replace& params)
void KyotoTyrantService::server::append(msgpack::rpc::request::type<void> req, KyotoTyrantService::append& params)
void KyotoTyrantService::server::cas(msgpack::rpc::request::type<bool> req, KyotoTyrantService::cas& params)
void KyotoTyrantService::server::remove(msgpack::rpc::request::type<bool> req, KyotoTyrantService::remove& params)
void KyotoTyrantService::server::get(msgpack::rpc::request::type<msgpack::type::raw_ref> req, KyotoTyrantService::get& params)
void KyotoTyrantService::server::match_prefix(msgpack::rpc::request::type<std::vector<msgpack::type::raw_ref> > req, KyotoTyrantService::match_prefix& params)
void KyotoTyrantService::server::match_regex(msgpack::rpc::request::type<std::vector<msgpack::type::raw_ref> > req, KyotoTyrantService::match_regex& params)
void KyotoTyrantService::server::uptime(msgpack::rpc::request::type<double> req, KyotoTyrantService::uptime& params)
*/


#endif
