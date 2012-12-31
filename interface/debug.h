
//__LINE__
//__FILE__
//__FUNCTION__
//__VA_ARGS__
#define DEBUG 0
#define TRACE 0

typedef struct {
	int type;
	char *name;
} DEBUG_SYSTEM;

enum DEBUG_TYPE {
	MAIN,
	DRIVER,
	SYSTEM,
};

DEBUG_SYSTEM test_debug[] = {
	MAIN, "MAIN",
	DRIVER, "DRIVER",
	SYSTEM, "SYSTEM",
};


enum DEBUG_KIND {
	DEBUG_FILE,
	DEBUG_DB,
	DEBUG_SYSLOG,
	DEBUG_TCP,
};

#define DEBUG_SART_LOG	"-------------- DEBUG START -------------\n"
#define DEBUG_END_LOG	"-------------- DEBUG_END   -------------\n"

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
