/*	Copyright (c) 2007-2019, Mark Wong */

#ifndef _PG_H_
#define _PG_H_

#include <libpq-fe.h>

#define CHECK_FOR_STATEMENTS_X \
		"SELECT 1\n" \
		"FROM pg_extension\n" \
		"WHERE extname = 'pg_stat_statements'"

#define SELECT_INDEX_STATS \
		"SELECT indexrelid, indexrelname, idx_scan, idx_tup_read,\n" \
		"       idx_tup_fetch\n" \
		"FROM pg_stat_user_indexes\n" \
		"ORDER BY indexrelname"

#define SELECT_TABLE_STATS \
		"SELECT relid, relname, seq_scan, seq_tup_read, idx_scan,\n" \
		"       idx_tup_fetch, n_tup_ins, n_tup_upd, n_tup_del\n" \
		"FROM pg_stat_user_tables\n" \
		"ORDER BY relname"

#define SELECT_STATEMENTS \
		"WITH aggs AS (\n" \
		"    SELECT sum(calls) AS calls_total\n" \
		"    FROM pg_stat_statements\n" \
		")\n" \
		"SELECT calls,\n" \
		"       calls / calls_total AS calls_percentage,\n" \
		"       to_char(INTERVAL '1 milliseconds' * total_time,\n" \
		"               'HH24:MI:SS.MS'),\n" \
		"       to_char(INTERVAL '1 milliseconds' * (total_time / calls),\n" \
		"               'HH24:MI:SS.MS') AS average_time,\n" \
		"       regexp_replace(query, E'[\\n\\r]+', ' ', 'g' ) AS query\n" \
		"FROM pg_stat_statements, aggs\n" \
		"ORDER BY %d ASC"

/* Table statistics comparison functions for qsort. */
int			compare_idx_scan_t(const void *, const void *);
int			compare_idx_tup_fetch_t(const void *, const void *);
int			compare_n_tup_del(const void *, const void *);
int			compare_n_tup_ins(const void *, const void *);
int			compare_n_tup_upd(const void *, const void *);
int			compare_seq_scan(const void *, const void *);
int			compare_seq_tup_read(const void *, const void *);

/* Index statistics comparison functions for qsort. */
int			compare_idx_scan(const void *, const void *);
int			compare_idx_tup_fetch(const void *, const void *);
int			compare_idx_tup_read(const void *, const void *);

PGconn	   *connect_to_db(const char **);

void		pg_display_index_stats(const char **, int, int);
void		pg_display_table_stats(const char **, int, int);
int			pg_display_statements(const char **, int, int);

PGresult   *pg_locks(PGconn *, int);
PGresult   *pg_processes(PGconn *);
PGresult   *pg_query(PGconn *, int);

extern char *index_ordernames[];
extern char *statement_ordernames[];
extern char *table_ordernames[];

#endif   /* _PG_H_ */
