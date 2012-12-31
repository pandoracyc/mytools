#include <stdio.h>
#include <stdarg.h>
#include "debug.h"

static FILE *debug_fp;
static int debug_level=0;
static char debug_filename[256];

int main(int argc, char *argv[]) {
	strcpy(debug_filename, "test.log");
	debug_start(DEBUG_FILE, debug_filename);
	debug_printf(TRACE, MAIN, "debug_filename : %s\n", debug_filename);
	debug_printf(TRACE, MAIN,  "debug_level : %d\n",debug_level);
	debug_printf(TRACE, MAIN,  "debug_fp : 0x%x\n",debug_fp);
	debug_end();
}


int debug_start(enum DEBUG_KIND kind, const char * output)
{
	debug_fp = fopen(output, "w");
	fprintf(debug_fp, DEBUG_SART_LOG);
}

void debug_printf(int level, int kind, char *fmt, ...)
{
	va_list argp;

	fprintf(debug_fp, "[%s] ", test_debug[kind].name);
	if(level<=debug_level) {
		va_start( argp, fmt );
		vfprintf(debug_fp, fmt, argp);
	}
}


void debug_end()
{
	fprintf(debug_fp, DEBUG_END_LOG);
	fclose(debug_fp);
}

