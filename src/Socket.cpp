#include "Socket.h"


bool zl_socket_startup()
{
#ifdef OS_WINDOWS
    WSADATA wsaData;
    int ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (ret != 0)
    {
        return false;
    }
#endif
    return true;
}

bool zl_socket_cleanup()
{
#ifdef OS_WINDOWS
    WSACleanup();
#endif
    return true;
}