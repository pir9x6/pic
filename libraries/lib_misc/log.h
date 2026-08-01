#ifndef LIB_MISC_LOG_H
#define LIB_MISC_LOG_H

#include "uart.h"

typedef enum
{
    LOG_LEVEL_TRACE,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_CRITICAL

} LOG_LEVEL_t;

#define LOG_ENABLE_COLOR
#define LOG_LEVEL_THRESHOLD     LOG_LEVEL_DEBUG

#define LOG_COLOR_RESET     "\033[0m"

#define LOG_BLACK           "\033[30m"
#define LOG_RED             "\033[31m"
#define LOG_GREEN           "\033[32m"
#define LOG_YELLOW          "\033[33m"
#define LOG_BLEU            "\033[34m"
#define LOG_MAGENTA         "\033[35m"
#define LOG_CYAN            "\033[36m"
#define LOG_WHITE           "\033[37m"

#define LOG_BACK_BLACK      "\033[40m"
#define LOG_BACK_RED        "\033[41m"
#define LOG_BACK_GREEN      "\033[42m"
#define LOG_BACK_YELLOW     "\033[43m"
#define LOG_BACK_BLEU       "\033[44m"
#define LOG_BACK_MAGENTA    "\033[45m"
#define LOG_BACK_CYAN       "\033[46m"
#define LOG_BACK_WHITE      "\033[47m"

#define LOG_BRIGHT_BLACK    "\033[90m"
#define LOG_BRIGHT_RED      "\033[91m"
#define LOG_BRIGHT_GREEN    "\033[92m"
#define LOG_BRIGHT_YELLOW   "\033[93m"
#define LOG_BRIGHT_BLUE     "\033[94m"
#define LOG_BRIGHT_MAGENTA  "\033[95m"
#define LOG_BRIGHT_CYAN     "\033[96m"
#define LOG_BRIGHT_WHITE    "\033[97m"

#ifdef LOG_ENABLE_COLOR

    #define LOG_PRINT(color, level, ...)     \
        do {                                 \
            printf(color "[" level "] " ); \
            printf(__VA_ARGS__);             \
            printf(LOG_COLOR_RESET);             \
            printf("\r\n");                  \
        } while(0)

#else

    #define LOG_PRINT(color, level, ...)     \
        do {                                 \
            printf("[" level "] ");          \
            printf(__VA_ARGS__);             \
            printf("\r\n");                  \
        } while(0)

#endif

#if LOG_LEVEL_THRESHOLD <= LOG_LEVEL_DEBUG
    #define LOG_DEBUG(...) LOG_PRINT(LOG_CYAN, "DEBUG", __VA_ARGS__)
#else
    #define LOG_DEBUG(...)
#endif

#if LOG_LEVEL_THRESHOLD <= LOG_LEVEL_INFO
    #define LOG_INFO(...) LOG_PRINT(LOG_GREEN, "INFO ", __VA_ARGS__)
#else
    #define LOG_INFO(...)
#endif

#if LOG_LEVEL_THRESHOLD <= LOG_LEVEL_WARNING
    #define LOG_WARNING(...) LOG_PRINT(LOG_YELLOW, "WARN ", __VA_ARGS__)
#else
    #define LOG_WARNING(...)
#endif

#if LOG_LEVEL_THRESHOLD <= LOG_LEVEL_ERROR
    #define LOG_ERROR(...) LOG_PRINT(LOG_RED, "ERROR", __VA_ARGS__)
#else
    #define LOG_ERROR(...)
#endif

#if LOG_LEVEL_THRESHOLD <= LOG_LEVEL_CRITICAL
    #define LOG_CRITICAL(...) LOG_PRINT(LOG_MAGENTA, "CRIT ", __VA_ARGS__)
#else
    #define LOG_CRITICAL(...)
#endif

/* /!\ Cost too much memory */
void log_printf(LOG_LEVEL_t level, const char *format, ...);

#endif
