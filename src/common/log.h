#pragma once

#ifndef NDEBUG
typedef enum log_tag {
    INFO,
    WARNING,
    ERROR
} LOG_TAG;

#define LOG_COLOR_END "\x1B[0;m"
#define LOG_COLOR_RED "\x1B[0;31m"
#define LOG_COLOR_GREEN "\x1B[0;32m"
#define LOG_COLOR_YELLOW "\x1B[0;33m"

static inline const char* tag_to_str(LOG_TAG tag) {
    switch(tag) {
        case INFO:
            return "INFO";
            break;
        case WARNING:
            return "WARNING";
            break;
        case ERROR:
            return "ERROR";
            break;
        default:
            return "NOTAG";
            break;
    }
}

static inline const char* tag_to_color(LOG_TAG tag) {
    switch(tag) {
        case INFO:
            return LOG_COLOR_GREEN;
            break;
        case WARNING:
            return LOG_COLOR_YELLOW;
            break;
        case ERROR:
            return LOG_COLOR_RED;
            break;
        default:
            return LOG_COLOR_END;
            break;
    }
}


void _log(LOG_TAG tag, 
          const char* const file_name, 
          int line_number, 
          const char* const fmt, 
          ...);

#define LOG_INFO(fmt, ...) _log(INFO, __FILE__, __LINE__, fmt, __VA_ARGS__);
#define LOG_WARNING(fmt, ...) _log(WARNING, __FILE__, __LINE__, fmt, __VA_ARGS__);
#define LOG_ERROR(fmt, ...) _log(ERROR, __FILE__, __LINE__, fmt, __VA_ARGS__);
#else
#define LOG_INFO(fmt, ...) 
#define LOG_WARNING(fmt, ...) 
#define LOG_ERROR(fmt, ...) 
#endif

void log_init( void );
void log_flush( void );
void log_close( void );
