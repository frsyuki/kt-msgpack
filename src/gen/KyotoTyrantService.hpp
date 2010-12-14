#ifndef MPRPC_KyotoTyrantService_a15b55bd_HPP__
#define MPRPC_KyotoTyrantService_a15b55bd_HPP__

#include "types.hpp"


namespace KyotoTyrantService {


struct count {

	count()
	{
	}


	template <typename Packer>
	void msgpack_pack(Packer& _Pk) const {
		_Pk.pack_array(0);
	}

	void msgpack_unpack(msgpack::object _Obj) {
		if(_Obj.type != msgpack::type::ARRAY) {
			throw msgpack::type_error();
		}
		const size_t _Length = _Obj.via.array.size;
		msgpack::object* const _Array = _Obj.via.array.ptr;

		if(_Length < 0) {
			throw msgpack::type_error();
		}

	}
};
struct size {

	size()
	{
	}


	template <typename Packer>
	void msgpack_pack(Packer& _Pk) const {
		_Pk.pack_array(0);
	}

	void msgpack_unpack(msgpack::object _Obj) {
		if(_Obj.type != msgpack::type::ARRAY) {
			throw msgpack::type_error();
		}
		const size_t _Length = _Obj.via.array.size;
		msgpack::object* const _Array = _Obj.via.array.ptr;

		if(_Length < 0) {
			throw msgpack::type_error();
		}

	}
};
struct set {

	set()
		:
		xt(C_INT64_MAX)
	{
	}

	msgpack::type::raw_ref key;
	msgpack::type::raw_ref value;
	int64_t xt;

	template <typename Packer>
	void msgpack_pack(Packer& _Pk) const {
		_Pk.pack_array(3);
		_Pk.pack(key);
		_Pk.pack(value);
		_Pk.pack(xt);
	}

	void msgpack_unpack(msgpack::object _Obj) {
		if(_Obj.type != msgpack::type::ARRAY) {
			throw msgpack::type_error();
		}
		const size_t _Length = _Obj.via.array.size;
		msgpack::object* const _Array = _Obj.via.array.ptr;

		if(_Length < 2) {
			throw msgpack::type_error();
		}


			_Array[0].convert(&key);


			_Array[1].convert(&value);


			if(_Length <= 2) { return; }
			if(!_Array[2].is_nil()) {
				_Array[2].convert(&xt);
			}

	}
};
struct add {

	add()
		:
		xt(C_INT64_MAX)
	{
	}

	msgpack::type::raw_ref key;
	msgpack::type::raw_ref value;
	int64_t xt;

	template <typename Packer>
	void msgpack_pack(Packer& _Pk) const {
		_Pk.pack_array(3);
		_Pk.pack(key);
		_Pk.pack(value);
		_Pk.pack(xt);
	}

	void msgpack_unpack(msgpack::object _Obj) {
		if(_Obj.type != msgpack::type::ARRAY) {
			throw msgpack::type_error();
		}
		const size_t _Length = _Obj.via.array.size;
		msgpack::object* const _Array = _Obj.via.array.ptr;

		if(_Length < 2) {
			throw msgpack::type_error();
		}


			_Array[0].convert(&key);


			_Array[1].convert(&value);


			if(_Length <= 2) { return; }
			if(!_Array[2].is_nil()) {
				_Array[2].convert(&xt);
			}

	}
};
struct replace {

	replace()
		:
		xt(C_INT64_MAX)
	{
	}

	msgpack::type::raw_ref key;
	msgpack::type::raw_ref value;
	int64_t xt;

	template <typename Packer>
	void msgpack_pack(Packer& _Pk) const {
		_Pk.pack_array(3);
		_Pk.pack(key);
		_Pk.pack(value);
		_Pk.pack(xt);
	}

	void msgpack_unpack(msgpack::object _Obj) {
		if(_Obj.type != msgpack::type::ARRAY) {
			throw msgpack::type_error();
		}
		const size_t _Length = _Obj.via.array.size;
		msgpack::object* const _Array = _Obj.via.array.ptr;

		if(_Length < 2) {
			throw msgpack::type_error();
		}


			_Array[0].convert(&key);


			_Array[1].convert(&value);


			if(_Length <= 2) { return; }
			if(!_Array[2].is_nil()) {
				_Array[2].convert(&xt);
			}

	}
};
struct append {

	append()
		:
		xt(C_INT64_MAX)
	{
	}

	msgpack::type::raw_ref key;
	msgpack::type::raw_ref value;
	int64_t xt;

	template <typename Packer>
	void msgpack_pack(Packer& _Pk) const {
		_Pk.pack_array(3);
		_Pk.pack(key);
		_Pk.pack(value);
		_Pk.pack(xt);
	}

	void msgpack_unpack(msgpack::object _Obj) {
		if(_Obj.type != msgpack::type::ARRAY) {
			throw msgpack::type_error();
		}
		const size_t _Length = _Obj.via.array.size;
		msgpack::object* const _Array = _Obj.via.array.ptr;

		if(_Length < 2) {
			throw msgpack::type_error();
		}


			_Array[0].convert(&key);


			_Array[1].convert(&value);


			if(_Length <= 2) { return; }
			if(!_Array[2].is_nil()) {
				_Array[2].convert(&xt);
			}

	}
};
struct cas {

	cas()
		:
		xt(C_INT64_MAX)
	{
	}

	msgpack::type::raw_ref key;
	msgpack::type::raw_ref ovalue;
	msgpack::type::raw_ref nvalue;
	int64_t xt;

	template <typename Packer>
	void msgpack_pack(Packer& _Pk) const {
		_Pk.pack_array(4);
		_Pk.pack(key);
		_Pk.pack(ovalue);
		_Pk.pack(nvalue);
		_Pk.pack(xt);
	}

	void msgpack_unpack(msgpack::object _Obj) {
		if(_Obj.type != msgpack::type::ARRAY) {
			throw msgpack::type_error();
		}
		const size_t _Length = _Obj.via.array.size;
		msgpack::object* const _Array = _Obj.via.array.ptr;

		if(_Length < 3) {
			throw msgpack::type_error();
		}


			_Array[0].convert(&key);


			_Array[1].convert(&ovalue);


			_Array[2].convert(&nvalue);


			if(_Length <= 3) { return; }
			if(!_Array[3].is_nil()) {
				_Array[3].convert(&xt);
			}

	}
};
struct remove {

	remove()
	{
	}

	msgpack::type::raw_ref key;

	template <typename Packer>
	void msgpack_pack(Packer& _Pk) const {
		_Pk.pack_array(1);
		_Pk.pack(key);
	}

	void msgpack_unpack(msgpack::object _Obj) {
		if(_Obj.type != msgpack::type::ARRAY) {
			throw msgpack::type_error();
		}
		const size_t _Length = _Obj.via.array.size;
		msgpack::object* const _Array = _Obj.via.array.ptr;

		if(_Length < 1) {
			throw msgpack::type_error();
		}


			_Array[0].convert(&key);

	}
};
struct get {

	get()
	{
	}

	msgpack::type::raw_ref key;

	template <typename Packer>
	void msgpack_pack(Packer& _Pk) const {
		_Pk.pack_array(1);
		_Pk.pack(key);
	}

	void msgpack_unpack(msgpack::object _Obj) {
		if(_Obj.type != msgpack::type::ARRAY) {
			throw msgpack::type_error();
		}
		const size_t _Length = _Obj.via.array.size;
		msgpack::object* const _Array = _Obj.via.array.ptr;

		if(_Length < 1) {
			throw msgpack::type_error();
		}


			_Array[0].convert(&key);

	}
};
struct match_prefix {

	match_prefix()
		:
		max(-1)
	{
	}

	msgpack::type::raw_ref prefix;
	int64_t max;

	template <typename Packer>
	void msgpack_pack(Packer& _Pk) const {
		_Pk.pack_array(2);
		_Pk.pack(prefix);
		_Pk.pack(max);
	}

	void msgpack_unpack(msgpack::object _Obj) {
		if(_Obj.type != msgpack::type::ARRAY) {
			throw msgpack::type_error();
		}
		const size_t _Length = _Obj.via.array.size;
		msgpack::object* const _Array = _Obj.via.array.ptr;

		if(_Length < 1) {
			throw msgpack::type_error();
		}


			_Array[0].convert(&prefix);


			if(_Length <= 1) { return; }
			if(!_Array[1].is_nil()) {
				_Array[1].convert(&max);
			}

	}
};
struct match_regex {

	match_regex()
		:
		max(-1)
	{
	}

	msgpack::type::raw_ref regex;
	int64_t max;

	template <typename Packer>
	void msgpack_pack(Packer& _Pk) const {
		_Pk.pack_array(2);
		_Pk.pack(regex);
		_Pk.pack(max);
	}

	void msgpack_unpack(msgpack::object _Obj) {
		if(_Obj.type != msgpack::type::ARRAY) {
			throw msgpack::type_error();
		}
		const size_t _Length = _Obj.via.array.size;
		msgpack::object* const _Array = _Obj.via.array.ptr;

		if(_Length < 1) {
			throw msgpack::type_error();
		}


			_Array[0].convert(&regex);


			if(_Length <= 1) { return; }
			if(!_Array[1].is_nil()) {
				_Array[1].convert(&max);
			}

	}
};
struct uptime {

	uptime()
	{
	}


	template <typename Packer>
	void msgpack_pack(Packer& _Pk) const {
		_Pk.pack_array(0);
	}

	void msgpack_unpack(msgpack::object _Obj) {
		if(_Obj.type != msgpack::type::ARRAY) {
			throw msgpack::type_error();
		}
		const size_t _Length = _Obj.via.array.size;
		msgpack::object* const _Array = _Obj.via.array.ptr;

		if(_Length < 0) {
			throw msgpack::type_error();
		}

	}
};


}  // namespace KyotoTyrantService

#endif
