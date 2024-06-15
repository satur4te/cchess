#include "common/log.h"
#include <stdio.h>
#include <stdarg.h>

#if ! defined(NDEBUG) && defined(__LOGFILE__)
static FILE* fp;
#define __LOGPATH__ "cchess.log"
#endif

#ifndef NDEBUG
__attribute__((__format__ (__printf__, 4, 0)))
void _log(LOG_TAG tag, 
          const char* const file_name, 
          int line_number, 
          const char* const fmt, ...)
{
    va_list args;
    va_start(args, fmt);
#ifdef __LOGFILE__
    if(fp)
    {
        fprintf(fp ,"%s:%d [%s]: ", file_name, line_number, tag_to_str(tag));
        vfprintf(fp, fmt, args);
        log_flush();
    }
#endif
    printf("%s%s:%d [%s]%s: ", tag_to_color(tag), file_name, line_number, tag_to_str(tag), LOG_COLOR_END);
    vprintf(fmt, args);
}
#endif

void log_init( void ) 
{
#ifdef __LOGFILE__
    fp = fopen(__LOGPATH__, "w+");
#endif
}

void log_flush( void ) 
{
#ifdef __LOGFILE__
    if (fp)
        fflush(fp);
#endif
}

void log_close( void )
{
#ifdef __LOGFILE__
    if (fp)
        fclose(fp);
#endif
}

