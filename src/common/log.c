#include <stdio.h>
#include "common/log.h"

#ifdef DEBUG
static FILE* fp;
#endif

#ifdef DEBUG
void _log(const char* const tag, const char* const fmt, ...)
{
    va_list args;
    va_start(args, fmt);
#ifdef __LOGFILE__
    if(fp != NULL)
    {
        fprintf(fp ,"[%s]: ", tag);
        vfprintf(fp, fmt, args);
    }
#else
    printf("[%s]: ", tag);
    vprintf(fmt, args);
#endif
}
#endif

void log_init( void ) 
{
#ifdef __LOGFILE__
    fp = fopen(__LOGFILE__, "w+");
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

