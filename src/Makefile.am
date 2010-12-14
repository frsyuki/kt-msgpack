
plugindir = $(libexecdir)

plugin_LTLIBRARIES = libktmsgpack.la

libktmsgpack_la_SOURCES = \
	kt-msgpack.cc \
	gen/KyotoTyrantService.cpp

noinst_HEADERS = \
	gen/KyotoTyrantService.hpp \
	gen/KyotoTyrantService_client.hpp \
	gen/KyotoTyrantService_server.hpp \
	gen/client.hpp \
	gen/server.hpp \
	gen/types.hpp

# -version-info CURRENT:REVISION:AGE
libktmsgpack_la_LDFLAGS = -version-info 0:0:0

EXTRA_DIST = kt.thrift

