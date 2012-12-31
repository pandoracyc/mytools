//__VA_ARGS__
#define DEFAULT_DEBUG_LEVEL 0
#define TRACE 0

typedef struct {
	int type;
	char *name;
} DEBUG_SYSTEM;

enum DEBUG_TYPE {
	MAIN,
	DRIVER,
	SYSTEM,
	FUNCTION,
};

#define ADD_SYSTEM(name)	name, #name ,
DEBUG_SYSTEM test_debug[] = {
	ADD_SYSTEM(MAIN)
	ADD_SYSTEM(DRIVER)
	ADD_SYSTEM(SYSTEM)
	ADD_SYSTEM(FUNCTION)
};


enum DEBUG_KIND {
	DEBUG_FILE,
	DEBUG_DB,
	DEBUG_SYSLOG,
	DEBUG_TCP,
};

#define DEBUG_SART_LOG	"-------------- DEBUG START -------------\n"
#define DEBUG_END_LOG	"-------------- DEBUG_END   -------------\n"

#define LOG_TRACE_START	debug_printf(TRACE, FUNCTION, "%s:%d %s() START \n", __FILE__, __LINE__, __FUNCTION__);




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
