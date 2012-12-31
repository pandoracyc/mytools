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

#define ADD_SYSTEM(out,name)	out, #name ,
DEBUG_SYSTEM test_debug[] = {
	ADD_SYSTEM(1, MAIN)
	ADD_SYSTEM(1, DRIVER)
	ADD_SYSTEM(1, SYSTEM)
	ADD_SYSTEM(1, FUNCTION)
};


enum DEBUG_KIND {
	DEBUG_FILE,
	DEBUG_DB,
	DEBUG_SYSLOG,
	DEBUG_TCP,
	DEBUG_HTML,
	DEBUG_CSV,
};

#define DEBUG_SART_LOG	"------------------------------------------ DEBUG START -----------------------------------------\n"
#define DEBUG_END_LOG	"------------------------------------------ DEBUG_END   -----------------------------------------\n"

#define LOG_TRACE_START	debug_printf(TRACE, FUNCTION, "%s:%d %s() START \n", __FILE__, __LINE__, __FUNCTION__);
#define LOG_TRACE_END	debug_printf(TRACE, FUNCTION, "%s:%d %s() END \n", __FILE__, __LINE__, __FUNCTION__);




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
