#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include "debug.h"

static FILE *debug_fp;
static int debug_level = DEFAULT_DEBUG_LEVEL;
static int debug_time = DEFAULT_DEBUG_PRINT_TIME;
static char debug_filename[256];

#ifdef DEBUG_MAIN_TEST
void func001(void){
LOG_TRACE_START
	debug_printf(TRACE, DRIVER, "test\n");
LOG_TRACE_END
return;
}

int main(int argc, char *argv[]) {
	strcpy(debug_filename, "test.log");
	debug_start(DEBUG_FILE, debug_filename);
	debug_printf(TRACE, MAIN, "debug_filename : %s\n", debug_filename);
	debug_printf(TRACE, MAIN,  "debug_level : %d\n",debug_level);
	debug_printf(TRACE, MAIN,  "debug_fp : 0x%x\n",debug_fp);
	func001();
	debug_end();
}
#endif

int debug_start(enum DEBUG_KIND kind, const char * output)
{
	debug_fp = fopen(output, "w");
	fprintf(debug_fp, DEBUG_SART_LOG);
}

void debug_printf(int level, int kind, char *fmt, ...)
{
	va_list argp;
	time_t timer;
	struct tm *tm;
	char buf[255];

	if(level<=debug_level && test_debug[kind].out) {
		if (debug_time == 1) {
			time(&timer);
			tm = localtime(&timer);
			strftime(buf, sizeof(buf), OUTPUT_TIME_FORMAT, tm);
			fprintf(debug_fp, "[%s] ", buf);
		}
		fprintf(debug_fp, "[%s] ", test_debug[kind].name);
		va_start( argp, fmt );
		vfprintf(debug_fp, fmt, argp);
	}
}


void debug_end()
{
	fprintf(debug_fp, DEBUG_END_LOG);
	fclose(debug_fp);
}

