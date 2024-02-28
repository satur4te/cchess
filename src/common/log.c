#include "common/log.h"
#include <stdio.h>
#include <stdarg.h>
#if defined(DEBUG) && defined(__LOGFILE__)
static FILE* fp;
#define __LOGPATH__ "cchess.log"
#endif

#ifdef DEBUG
__attribute__((__format__ (__printf__, 4, 0)))
void _log(const char* const tag, 
          const char* const file_name, 
          int line_number, 
          const char* const fmt, ...)
{
    va_list args;
    va_start(args, fmt);
#ifdef __LOGFILE__
    if(fp != NULL)
    {
        fprintf(fp ,"%s:%d [%s]: ", file_name, line_number, tag);
        vfprintf(fp, fmt, args);
    }
#else
    printf("%s:%d [%s]: ", file_name, line_number, tag);
    vprintf(fmt, args);
#endif
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
    fflush(fp);
#endif

}
void log_close( void )
{
#ifdef __LOGFILE__
    fclose(fp);
#endif
}

