#include "stdio.h"
#include "stdarg.h"

#include "log.h"
#include "uart.h"

static const char *level_color[] =
{
    LOG_CYAN,       // DEBUG
    LOG_GREEN,      // INFO
    LOG_YELLOW,     // WARNING
    LOG_RED,        // ERROR
    LOG_MAGENTA     // CRITICAL
};

static const char *level_string[] =
{
    "DEBUG",
    "INFO ",
    "WARN ",
    "ERROR",
    "CRIT "
};

/* /!\ vprintf costs too much memory, use defines instead */
void log_printf(LOG_LEVEL_t level, const char *format, ...)
{

    if (level < LOG_LEVEL_THRESHOLD)
        return;

#ifdef LOG_ENABLE_COLOR

    printf("%s", level_color[level]);

#endif

    printf("[%s] ", level_string[level]);

    va_list args;

    va_start(args, format);

    vprintf(format, args);

    va_end(args);

#ifdef LOG_ENABLE_COLOR

    printf("%s", LOG_COLOR_RESET);

#endif


    printf("\r\n");
}
