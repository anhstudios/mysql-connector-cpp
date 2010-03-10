/*
   Copyright (c) 2009, 2010, Oracle and/or its affiliates. All rights reserved.

   The MySQL Connector/C++ is licensed under the terms of the GPL
   <http://www.gnu.org/licenses/old-licenses/gpl-2.0.html>, like most
   MySQL Connectors. There are special exceptions to the terms and
   conditions of the GPL as it is applied to this software, see the
   FLOSS License Exception
   <http://www.mysql.com/about/legal/licensing/foss-exception.html>.
*/

#ifndef _MYSQL_CONNECTION_PROXY_H_
#define _MYSQL_CONNECTION_PROXY_H_

#include "native_connection_wrapper.h"

#include <boost/shared_ptr.hpp>


namespace sql
{
namespace mysql
{
namespace NativeAPI
{
class IMySQLCAPI;


inline const char * nullIfEmpty(const ::sql::SQLString & str)
{
  return str.length() > 0 ? str.c_str() : NULL;
}


class MySQL_NativeConnectionWrapper : public NativeConnectionWrapper
{
	boost::shared_ptr< IMySQLCAPI >	api;

	struct ::st_mysql *				mysql;

	::sql::SQLString				serverInfo;


	MySQL_NativeConnectionWrapper(){}

public:

	MySQL_NativeConnectionWrapper(const ::sql::SQLString & clientFileName);

	virtual ~MySQL_NativeConnectionWrapper();


	uint64_t affected_rows();

	bool autocommit(bool);

	bool connect(const ::sql::SQLString & host,
				const ::sql::SQLString & user,
				const ::sql::SQLString & passwd,
				const ::sql::SQLString & db,
				unsigned int			 port,
				const ::sql::SQLString & socket_or_pipe,
				unsigned long			client_flag);

	bool commit();

	void debug(const ::sql::SQLString &);

	unsigned int errNo();

	::sql::SQLString error();

	::sql::SQLString escapeString(const ::sql::SQLString &);

	unsigned int field_count();

	unsigned long get_client_version();

	const ::sql::SQLString & get_server_info();

	unsigned long get_server_version();

	bool more_results();

	int next_result();

	int options(::sql::mysql::MySQL_Connection_Options, const void * );

	int query(const ::sql::SQLString &);

	int ping();

	/* int real_query(const ::sql::SQLString &, uint64_t);*/


	bool rollback();

	::sql::SQLString sqlstate();

	bool ssl_set(const ::sql::SQLString & key,
				const ::sql::SQLString & cert,
				const ::sql::SQLString & ca,
				const ::sql::SQLString & capath,
				const ::sql::SQLString & cipher);

	NativeResultsetWrapper * store_result();

	NativeResultsetWrapper * use_result();


	NativeStatementWrapper & stmt_init();
};

} /* namespace NativeAPI */
} /* namespace mysql */
} /* namespace sql */
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
