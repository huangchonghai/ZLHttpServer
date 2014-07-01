#ifndef INCLUDE_HTTPLOG_FILE_H
#define INCLUDE_HTTPLOG_FILE_H
/***********************************************************************
2013-09-25 21:02:15
lizheng
***********************************************************************/

#include <cstdio>

namespace ZL
{

    class HttpLog
    {
    public:
        HttpLog(const char *name);
        ~HttpLog();

    public:
        void Print(char *message, ...);

    private:
        FILE   *file_;
    };

    extern HttpLog		g_httplog;

} /* namespace ZL */

#endif
