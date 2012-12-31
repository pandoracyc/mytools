#include "error_message.h"

#ifndef __DEBUG_H__
#define __DEBUG_H__

#define DEFAULT_DEBUG_PRINT_TIME 1
#define OUTPUT_TIME_FORMAT "%Y/%m/%d_%H:%M:%S"
#define DEFAULT_DEBUG_LEVEL 5

#define FATAL 0
#define ERROR 1
#define WARN  2
#define INFO  3
#define DEBUG 4
#define TRACE 5

typedef struct {
	int  out;
	char *name;
} DEBUG_SYSTEM;

enum DEBUG_TYPE {
	MAIN,
	DRIVER,
	SYSTEM,
	FUNCTION,
};


enum DEBUG_KIND {
	DEBUG_STDOUT,
	DEBUG_FILE,
	DEBUG_DB,
	DEBUG_SYSLOG,
	DEBUG_TCP,
	DEBUG_HTML,
	DEBUG_CSV,
};

#define DEBUG_SART_LOG	"------------------------------------------ DEBUG START -----------------------------------------\n"
#define DEBUG_END_LOG	"------------------------------------------ DEBUG_END   -----------------------------------------\n"

extern int log_tree_level;
/* 関数のトレース開始ログを出力 */
#define LOG_TRACE_START	\
{ \
log_tree_level++; \
debug_printf(TRACE, FUNCTION, "%s:%d:%s() START(%d) \n", __FILE__, __LINE__, __FUNCTION__, log_tree_level); \
}

/* 関数のトレース終了ログを出力 */
#define LOG_TRACE_END	\
{ \
debug_printf(TRACE, FUNCTION, "%s:%d:%s() END(%d) \n", __FILE__, __LINE__, __FUNCTION__, log_tree_level); \
log_tree_level--; \
} 

/**
 * ログ出力を開始する
 * @param kind 
 * <pre>
 * FILE
 * DATABASE
 * </pre>
 */
int debug_start(enum DEBUG_KIND kind, const char * output);

/**
 * ERROR文を出力する
 */
void debug_printf(int level, int type, char *fmt, ...);


/**
 * ログ出力を終了する
 */
void debug_end();

#endif// __DEBUG_H__
