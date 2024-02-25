#pragma once

#include <stdarg.h>
#include <stdio.h>

#ifdef DEBUG
void _log(const char* const tag, const char* const fmt, ...);
#define __LOGFILE__ "cchess.log"
#define LOG_INFO(fmt, ...) _log("INFO", fmt, ##__VA_ARGS__);
#define LOG_WARNING(fmt, ...) _log("WARNING", fmt, ##__VA_ARGS__);
#define LOG_ERROR(fmt, ...) _log("ERROR", fmt, ##__VA_ARGS__);
#else
#define LOG_INFO(fmt, ...) 
#define LOG_WARNING(fmt, ...) 
#define LOG_ERROR(fmt, ...) 
#endif

void log_init( void );
void log_flush( void );
void log_close( void );
