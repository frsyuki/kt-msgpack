#ifndef MPRPC_KyotoTyrantService_client_72b73bb2_HPP__
#define MPRPC_KyotoTyrantService_client_72b73bb2_HPP__

#include "KyotoTyrantService.hpp"


namespace KyotoTyrantService {


class client : public msgpack::rpc::client::base {
public:
	client(const msgpack::rpc::address& addr, msgpack::rpc::loop lo = msgpack::rpc::loop()) :
		msgpack::rpc::client::base(addr, lo) { }

	client(const std::string& host, uint16_t port, msgpack::rpc::loop lo = msgpack::rpc::loop()) :
		msgpack::rpc::client::base(host, port, lo) { }

	~client() { }

	uint64_t count_apply(
			const KyotoTyrantService::count& message) {
		return instance.call_apply("count", message).get<uint64_t>();
	}

	uint64_t count(
			) {
		KyotoTyrantService::count _Message;
		return count_apply(_Message);
	}

	msgpack::rpc::future::type<uint64_t> count_async_apply(
			const KyotoTyrantService::count& message) {
		return instance.call_apply("count", message);
	}

	msgpack::rpc::future::type<uint64_t> count_async(
			) {
		KyotoTyrantService::count _Message;
		return count_async_apply(_Message);
	}
	uint64_t size_apply(
			const KyotoTyrantService::size& message) {
		return instance.call_apply("size", message).get<uint64_t>();
	}

	uint64_t size(
			) {
		KyotoTyrantService::size _Message;
		return size_apply(_Message);
	}

	msgpack::rpc::future::type<uint64_t> size_async_apply(
			const KyotoTyrantService::size& message) {
		return instance.call_apply("size", message);
	}

	msgpack::rpc::future::type<uint64_t> size_async(
			) {
		KyotoTyrantService::size _Message;
		return size_async_apply(_Message);
	}
	void set_apply(
			const KyotoTyrantService::set& message) {
		instance.call_apply("set", message).get<void>();
	}

	void set(
			const msgpack::type::raw_ref& key, const msgpack::type::raw_ref& value, const int64_t& xt) {
		KyotoTyrantService::set _Message;
		_Message.key = key;
		_Message.value = value;
		_Message.xt = xt;
		return set_apply(_Message);
	}

	msgpack::rpc::future::type<void> set_async_apply(
			const KyotoTyrantService::set& message) {
		return instance.call_apply("set", message);
	}

	msgpack::rpc::future::type<void> set_async(
			const msgpack::type::raw_ref& key, const msgpack::type::raw_ref& value, const int64_t& xt) {
		KyotoTyrantService::set _Message;
		_Message.key = key;
		_Message.value = value;
		_Message.xt = xt;
		return set_async_apply(_Message);
	}
	bool add_apply(
			const KyotoTyrantService::add& message) {
		return instance.call_apply("add", message).get<bool>();
	}

	bool add(
			const msgpack::type::raw_ref& key, const msgpack::type::raw_ref& value, const int64_t& xt) {
		KyotoTyrantService::add _Message;
		_Message.key = key;
		_Message.value = value;
		_Message.xt = xt;
		return add_apply(_Message);
	}

	msgpack::rpc::future::type<bool> add_async_apply(
			const KyotoTyrantService::add& message) {
		return instance.call_apply("add", message);
	}

	msgpack::rpc::future::type<bool> add_async(
			const msgpack::type::raw_ref& key, const msgpack::type::raw_ref& value, const int64_t& xt) {
		KyotoTyrantService::add _Message;
		_Message.key = key;
		_Message.value = value;
		_Message.xt = xt;
		return add_async_apply(_Message);
	}
	bool replace_apply(
			const KyotoTyrantService::replace& message) {
		return instance.call_apply("replace", message).get<bool>();
	}

	bool replace(
			const msgpack::type::raw_ref& key, const msgpack::type::raw_ref& value, const int64_t& xt) {
		KyotoTyrantService::replace _Message;
		_Message.key = key;
		_Message.value = value;
		_Message.xt = xt;
		return replace_apply(_Message);
	}

	msgpack::rpc::future::type<bool> replace_async_apply(
			const KyotoTyrantService::replace& message) {
		return instance.call_apply("replace", message);
	}

	msgpack::rpc::future::type<bool> replace_async(
			const msgpack::type::raw_ref& key, const msgpack::type::raw_ref& value, const int64_t& xt) {
		KyotoTyrantService::replace _Message;
		_Message.key = key;
		_Message.value = value;
		_Message.xt = xt;
		return replace_async_apply(_Message);
	}
	void append_apply(
			const KyotoTyrantService::append& message) {
		instance.call_apply("append", message).get<void>();
	}

	void append(
			const msgpack::type::raw_ref& key, const msgpack::type::raw_ref& value, const int64_t& xt) {
		KyotoTyrantService::append _Message;
		_Message.key = key;
		_Message.value = value;
		_Message.xt = xt;
		return append_apply(_Message);
	}

	msgpack::rpc::future::type<void> append_async_apply(
			const KyotoTyrantService::append& message) {
		return instance.call_apply("append", message);
	}

	msgpack::rpc::future::type<void> append_async(
			const msgpack::type::raw_ref& key, const msgpack::type::raw_ref& value, const int64_t& xt) {
		KyotoTyrantService::append _Message;
		_Message.key = key;
		_Message.value = value;
		_Message.xt = xt;
		return append_async_apply(_Message);
	}
	bool cas_apply(
			const KyotoTyrantService::cas& message) {
		return instance.call_apply("cas", message).get<bool>();
	}

	bool cas(
			const msgpack::type::raw_ref& key, const msgpack::type::raw_ref& ovalue, const msgpack::type::raw_ref& nvalue, const int64_t& xt) {
		KyotoTyrantService::cas _Message;
		_Message.key = key;
		_Message.ovalue = ovalue;
		_Message.nvalue = nvalue;
		_Message.xt = xt;
		return cas_apply(_Message);
	}

	msgpack::rpc::future::type<bool> cas_async_apply(
			const KyotoTyrantService::cas& message) {
		return instance.call_apply("cas", message);
	}

	msgpack::rpc::future::type<bool> cas_async(
			const msgpack::type::raw_ref& key, const msgpack::type::raw_ref& ovalue, const msgpack::type::raw_ref& nvalue, const int64_t& xt) {
		KyotoTyrantService::cas _Message;
		_Message.key = key;
		_Message.ovalue = ovalue;
		_Message.nvalue = nvalue;
		_Message.xt = xt;
		return cas_async_apply(_Message);
	}
	bool remove_apply(
			const KyotoTyrantService::remove& message) {
		return instance.call_apply("remove", message).get<bool>();
	}

	bool remove(
			const msgpack::type::raw_ref& key) {
		KyotoTyrantService::remove _Message;
		_Message.key = key;
		return remove_apply(_Message);
	}

	msgpack::rpc::future::type<bool> remove_async_apply(
			const KyotoTyrantService::remove& message) {
		return instance.call_apply("remove", message);
	}

	msgpack::rpc::future::type<bool> remove_async(
			const msgpack::type::raw_ref& key) {
		KyotoTyrantService::remove _Message;
		_Message.key = key;
		return remove_async_apply(_Message);
	}
	msgpack::type::raw_ref get_apply(
			const KyotoTyrantService::get& message) {
		return instance.call_apply("get", message).get<msgpack::type::raw_ref>();
	}

	msgpack::type::raw_ref get(
			const msgpack::type::raw_ref& key) {
		KyotoTyrantService::get _Message;
		_Message.key = key;
		return get_apply(_Message);
	}

	msgpack::rpc::future::type<msgpack::type::raw_ref> get_async_apply(
			const KyotoTyrantService::get& message) {
		return instance.call_apply("get", message);
	}

	msgpack::rpc::future::type<msgpack::type::raw_ref> get_async(
			const msgpack::type::raw_ref& key) {
		KyotoTyrantService::get _Message;
		_Message.key = key;
		return get_async_apply(_Message);
	}
	std::vector<msgpack::type::raw_ref>  match_prefix_apply(
			const KyotoTyrantService::match_prefix& message) {
		return instance.call_apply("match_prefix", message).get<std::vector<msgpack::type::raw_ref> >();
	}

	std::vector<msgpack::type::raw_ref>  match_prefix(
			const msgpack::type::raw_ref& prefix, const int64_t& max) {
		KyotoTyrantService::match_prefix _Message;
		_Message.prefix = prefix;
		_Message.max = max;
		return match_prefix_apply(_Message);
	}

	msgpack::rpc::future::type<std::vector<msgpack::type::raw_ref> > match_prefix_async_apply(
			const KyotoTyrantService::match_prefix& message) {
		return instance.call_apply("match_prefix", message);
	}

	msgpack::rpc::future::type<std::vector<msgpack::type::raw_ref> > match_prefix_async(
			const msgpack::type::raw_ref& prefix, const int64_t& max) {
		KyotoTyrantService::match_prefix _Message;
		_Message.prefix = prefix;
		_Message.max = max;
		return match_prefix_async_apply(_Message);
	}
	std::vector<msgpack::type::raw_ref>  match_regex_apply(
			const KyotoTyrantService::match_regex& message) {
		return instance.call_apply("match_regex", message).get<std::vector<msgpack::type::raw_ref> >();
	}

	std::vector<msgpack::type::raw_ref>  match_regex(
			const msgpack::type::raw_ref& regex, const int64_t& max) {
		KyotoTyrantService::match_regex _Message;
		_Message.regex = regex;
		_Message.max = max;
		return match_regex_apply(_Message);
	}

	msgpack::rpc::future::type<std::vector<msgpack::type::raw_ref> > match_regex_async_apply(
			const KyotoTyrantService::match_regex& message) {
		return instance.call_apply("match_regex", message);
	}

	msgpack::rpc::future::type<std::vector<msgpack::type::raw_ref> > match_regex_async(
			const msgpack::type::raw_ref& regex, const int64_t& max) {
		KyotoTyrantService::match_regex _Message;
		_Message.regex = regex;
		_Message.max = max;
		return match_regex_async_apply(_Message);
	}
	double uptime_apply(
			const KyotoTyrantService::uptime& message) {
		return instance.call_apply("uptime", message).get<double>();
	}

	double uptime(
			) {
		KyotoTyrantService::uptime _Message;
		return uptime_apply(_Message);
	}

	msgpack::rpc::future::type<double> uptime_async_apply(
			const KyotoTyrantService::uptime& message) {
		return instance.call_apply("uptime", message);
	}

	msgpack::rpc::future::type<double> uptime_async(
			) {
		KyotoTyrantService::uptime _Message;
		return uptime_async_apply(_Message);
	}
};


}  // namespace KyotoTyrantService


#endif
