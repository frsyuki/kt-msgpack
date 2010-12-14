
#include "KyotoTyrantService_server.hpp"
#include <memory>
#include <mp/unordered_map.h>


namespace KyotoTyrantService {


static void dispatch_count(server* svr, msgpack::rpc::request* preq)
{
	KyotoTyrantService::count message;
	preq->params().convert(&message);
	svr->count(*preq, message);
}
static void dispatch_size(server* svr, msgpack::rpc::request* preq)
{
	KyotoTyrantService::size message;
	preq->params().convert(&message);
	svr->size(*preq, message);
}
static void dispatch_set(server* svr, msgpack::rpc::request* preq)
{
	KyotoTyrantService::set message;
	preq->params().convert(&message);
	svr->set(*preq, message);
}
static void dispatch_add(server* svr, msgpack::rpc::request* preq)
{
	KyotoTyrantService::add message;
	preq->params().convert(&message);
	svr->add(*preq, message);
}
static void dispatch_replace(server* svr, msgpack::rpc::request* preq)
{
	KyotoTyrantService::replace message;
	preq->params().convert(&message);
	svr->replace(*preq, message);
}
static void dispatch_append(server* svr, msgpack::rpc::request* preq)
{
	KyotoTyrantService::append message;
	preq->params().convert(&message);
	svr->append(*preq, message);
}
static void dispatch_cas(server* svr, msgpack::rpc::request* preq)
{
	KyotoTyrantService::cas message;
	preq->params().convert(&message);
	svr->cas(*preq, message);
}
static void dispatch_remove(server* svr, msgpack::rpc::request* preq)
{
	KyotoTyrantService::remove message;
	preq->params().convert(&message);
	svr->remove(*preq, message);
}
static void dispatch_get(server* svr, msgpack::rpc::request* preq)
{
	KyotoTyrantService::get message;
	preq->params().convert(&message);
	svr->get(*preq, message);
}
static void dispatch_match_prefix(server* svr, msgpack::rpc::request* preq)
{
	KyotoTyrantService::match_prefix message;
	preq->params().convert(&message);
	svr->match_prefix(*preq, message);
}
static void dispatch_match_regex(server* svr, msgpack::rpc::request* preq)
{
	KyotoTyrantService::match_regex message;
	preq->params().convert(&message);
	svr->match_regex(*preq, message);
}
static void dispatch_uptime(server* svr, msgpack::rpc::request* preq)
{
	KyotoTyrantService::uptime message;
	preq->params().convert(&message);
	svr->uptime(*preq, message);
}

typedef mp::unordered_map<std::string, void (*)(server*, msgpack::rpc::request*)> table_type;
#define TABLE server::s_dispatch_table.pimpl
server::dispatch_table server::s_dispatch_table;

server::dispatch_table::dispatch_table()
{
	std::auto_ptr<table_type> table(new table_type());
	table->insert(std::make_pair("count", &dispatch_count));
	table->insert(std::make_pair("size", &dispatch_size));
	table->insert(std::make_pair("set", &dispatch_set));
	table->insert(std::make_pair("add", &dispatch_add));
	table->insert(std::make_pair("replace", &dispatch_replace));
	table->insert(std::make_pair("append", &dispatch_append));
	table->insert(std::make_pair("cas", &dispatch_cas));
	table->insert(std::make_pair("remove", &dispatch_remove));
	table->insert(std::make_pair("get", &dispatch_get));
	table->insert(std::make_pair("match_prefix", &dispatch_match_prefix));
	table->insert(std::make_pair("match_regex", &dispatch_match_regex));
	table->insert(std::make_pair("uptime", &dispatch_uptime));
	TABLE = (void*)table.release();
}

server::dispatch_table::~dispatch_table()
{
	delete (table_type*)TABLE;
}

void server::dispatch(msgpack::rpc::request req)
try {
	std::string method;
	req.method().convert(&method);

	const table_type* table((table_type*)TABLE);

	table_type::const_iterator m = table->find(method);
	if(m == table->end()) {
		req.error(msgpack::rpc::NO_METHOD_ERROR);
		return;
	}

	(*m->second)(this, &req);

} catch (msgpack::type_error& e) {
	req.error(msgpack::rpc::ARGUMENT_ERROR);
	return;

} catch (std::exception& e) {
	req.error(std::string(e.what()));
	return;
}


}  // namespace KyotoTyrantService

