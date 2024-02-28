#pragma once

#ifdef DEBUG
void _log(const char* const tag, 
          const char* const file_name, 
          int line_number, 
          const char* const fmt, 
          ...);

#define LOG_INFO(fmt, ...) _log("INFO", __FILE__, __LINE__, fmt, __VA_ARGS__);
#define LOG_WARNING(fmt, ...) _log("WARNING", __FILE__, __LINE__, fmt, __VA_ARGS__);
#define LOG_ERROR(fmt, ...) _log("ERROR", __FILE__, __LINE__, fmt, __VA_ARGS__);
#else
#define LOG_INFO(fmt, ...) 
#define LOG_WARNING(fmt, ...) 
#define LOG_ERROR(fmt, ...) 
#endif

void log_init( void );
void log_flush( void );
void log_close( void );
