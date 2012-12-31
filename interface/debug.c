#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include "debug.h"
#include "debug_tcp.h"

static FILE *debug_fp;
static int debug_level = DEFAULT_DEBUG_LEVEL;
static enum DEBUG_KIND debug_kind;
static int debug_time = DEFAULT_DEBUG_PRINT_TIME;
static char debug_filename[256];


#ifdef DEBUG_MAIN_TEST
void func002(void){
LOG_TRACE_START
	debug_printf(TRACE, DRIVER, "test\n");
LOG_TRACE_END
return;
}
void func001(void){
LOG_TRACE_START
	func002();
	func002();
	debug_printf(TRACE, DRIVER, "test\n");
LOG_TRACE_END
return;
}

int main(int argc, char *argv[]) {
	strcpy(debug_filename, "test.log");
	//debug_start(DEBUG_FILE, debug_filename);
	debug_start(DEBUG_TCP, debug_filename);
	debug_printf(TRACE, MAIN, "debug_filename : %s\n", debug_filename);
	debug_printf(TRACE, MAIN, "debug_kind : %d\n", debug_kind);
	debug_printf(TRACE, MAIN,  "debug_level : %d\n",debug_level);
	debug_printf(TRACE, MAIN,  "debug_fp : 0x%x\n",debug_fp);
	func001();
	debug_end();
	return 0;
}
#endif

int debug_start(enum DEBUG_KIND kind, const char * output)
{
	debug_kind = kind;
	switch (debug_kind) {
	case DEBUG_TCP:
		fprintf(stdout, "DEBUG_TCP\n");
		tcp_start();
		break;
	case DEBUG_FILE:
		fprintf(stdout, "DEBUG_FILE\n");
		printf("DEBUG_FILE\n",kind);
		debug_fp = fopen(output, "w");
		fprintf(debug_fp, DEBUG_SART_LOG);
		break;
	default:
		fprintf(stdout, "STDOUT\n");
		fprintf(stdout, DEBUG_SART_LOG);
		break;
	}
}

void debug_printf(int level, int kind, char *fmt, ...)
{
	va_list argp;
	time_t timer;
	struct tm *tm;
	char buf[255];
	char sendbuf[255];

	if(level<=debug_level && test_debug[kind].out) {
		if (debug_time == 1) {
			time(&timer);
			tm = localtime(&timer);
			strftime(buf, sizeof(buf), OUTPUT_TIME_FORMAT, tm);
		}
		va_start( argp, fmt );
		switch (debug_kind) {
		case DEBUG_TCP:
			memset(sendbuf,0x00,sizeof(sendbuf));
			if( test_debug[kind].out) {
				sprintf(sendbuf, "[T%s] ", buf);
				tcp_printf(sendbuf, strlen(sendbuf)+1);
			}
			memset(sendbuf,0x00,sizeof(sendbuf));
			vsprintf(sendbuf, fmt, argp);
			tcp_printf(sendbuf, strlen(sendbuf)+1);
			break;
		case DEBUG_FILE:
			if( test_debug[kind].out)
				fprintf(debug_fp, "[T%s] ", buf);
			fprintf(debug_fp, "[@%s] ", test_debug[kind].name);
			vfprintf(debug_fp, fmt, argp);
			break;
		default:
			if( test_debug[kind].out)
				fprintf(stdout, "[T%s] ", buf);
			fprintf(stdout, "[T%s] ", buf);
			fprintf(stdout, "[@%s] ", test_debug[kind].name);
			vfprintf(stdout, fmt, argp);
			break;
		}
		va_end(argp);
	}
}


void debug_end()
{
	switch (debug_kind) {
	case DEBUG_TCP:
		tcp_end();
		break;
	case DEBUG_FILE:
		fprintf(debug_fp, DEBUG_END_LOG);
		fclose(debug_fp);
		break;
	default:
		fprintf(stdout, DEBUG_END_LOG);
		break;
	}
}

