
const int64 C_INT64_MAX = 9223372036854775807

service KyotoTyrantService {
	uint64 count()
	uint64 size()
	void set(1:bytes key, 2:bytes value, 3:optional int64 xt = C_INT64_MAX)
	bool add(1:bytes key, 2:bytes value, 3:optional int64 xt = C_INT64_MAX)
	bool replace(1:bytes key, 2:bytes value, 3:optional int64 xt = C_INT64_MAX)
	void append(1:bytes key, 2:bytes value, 3:optional int64 xt = C_INT64_MAX)
	bool cas(1:bytes key, 2:bytes ovalue, 3:bytes nvalue, 4:optional int64 xt = C_INT64_MAX)
	bool remove(1:bytes key)
	bytes get(1:bytes key)
	list<bytes> match_prefix(1:bytes prefix, 2:optional int64 max = -1)
	list<bytes> match_regex(1:bytes regex, 2:optional int64 max = -1)

	double uptime()
}

