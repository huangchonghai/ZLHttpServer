// ***********************************************************************
// Filename         : Socket.h
// Author           : LIZHENG
// Created          : 2014-07-01
// Description      : socket�Ŀ�ƽ̨��װ
//
// Last Modified By : LIZHENG
// Last Modified On : 2014-07-01
// 
// Copyright (c) lizhenghn@gmail.com. All rights reserved.
// ***********************************************************************
#ifndef ZL_SOCKET_H
#define ZL_SOCKET_H

#include "OsDefine.h"
#ifdef OS_WINDOWS
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/utsname.h>
#include <unistd.h>
#endif

#ifdef OS_WINDOWS
typedef SOCKET ZL_SOCKET;
typedef SOCKADDR_IN  ZL_SOCKADDR_IN;
typedef int ZL_SOCKLEN;
typedef int ssize_t;

#define SHUT_RD                   0
#define SHUT_WR                   1
#define SHUT_RDWR                 2
#define ZL_CREATE_SOCKET(a,b,c)   socket(a,b,c)
#define ZL_BIND(a,b,c)            bind(a,b,c)
#define ZL_LISTEN(a,b)            listen(a,b)
#define ZL_ACCEPT(a,b,c)          accept(a,b,c)
#define ZL_CONNECT(a,b,c)         connect(a,b,c)
#define ZL_CLOSE(a)               closesocket(a)
#define ZL_READ(a,b,c)            _read(a,b,c)
#define ZL_RECV(a,b,c,d)          recv(a, (char *)b, c, d)
#define ZL_RECVFROM(a,b,c,d,e,f)  recvfrom(a, (char *)b, c, d, (sockaddr *)e, (int *)f)
#define ZL_SELECT(a,b,c,d,e)      select((int32)a,b,c,d,e)
#define ZL_SEND(a,b,c,d)          send(a, (const char *)b, (int)c, d)
#define ZL_SENDTO(a,b,c,d,e,f)    sendto(a, (const char *)b, (int)c, d, e, f)
#define ZL_SENDFILE(a,b,c,d)      sendfile(a, b, c, d)
#define ZL_WRITE(a,b,c)           write(a,b,c)
#define ZL_WRITEV(a,b,c)          Writev(b, c)
#define ZL_GETSOCKOPT(a,b,c,d,e)  getsockopt(a,b,c,(char *)d, (int *)e)
#define ZL_SETSOCKOPT(a,b,c,d,e)  setsockopt(a,b,c,(char *)d, (int)e)
#define ZL_GETHOSTBYNAME(a)       gethostbyname((const char *)a)
#define ZL_LSEEK(a,b,c)           _lseek(a,b,c)

#define ZL_INVALID_SOCKET		  INVALID_SOCKET
#define RECV_FLAGS                MSG_WAITALL
#define SEND_FLAGS                0
#define SET_SOCKET_ERROR(x,y)	  errno=y
#define SOCKET_ERROR_INTERUPT     EINTR
#define SOCKET_ERROR_TIMEDOUT     EAGAIN

#elif defined(OS_LINUX)
typedef int        ZL_SOCKET;
typedef int        ZL_SOCKADDR_IN;
typedef socklen_t  ZL_SOCKLEN;

#define ZL_CREATE_SOCKET(a,b,c)   socket(a,b,c)
#define ZL_BIND(a,b,c)            bind(a,b,c)
#define ZL_LISTEN(a,b)            listen(a,b)
#define ZL_ACCEPT(a,b,c)          accept(a,b,c)
#define ZL_CONNECT(a,b,c)         connect(a,b,c)
#define ZL_CLOSE(a)               close(a)
#define ZL_READ(a,b,c)            read(a,b,c)
#define ZL_RECV(a,b,c,d)          recv(a, (void *)b, c, d)
#define ZL_RECVFROM(a,b,c,d,e,f)  recvfrom(a, (char *)b, c, d, (sockaddr *)e, f)
#define ZL_RECV_FLAGS             MSG_WAITALL
#define ZL_SELECT(a,b,c,d,e)      select(a,b,c,d,e)
#define ZL_SEND(a,b,c,d)          send(a, (const int8 *)b, c, d)
#define ZL_SENDTO(a,b,c,d,e,f)    sendto(a, (const int8 *)b, c, d, e, f)
#define ZL_WRITE(a,b,c)           write(a,b,c)
#define ZL_WRITEV(a,b,c)          writev(a, b, c)
#define ZL_GETSOCKOPT(a,b,c,d,e)  getsockopt((int)a,(int)b,(int)c,(void *)d,(socklen_t *)e)
#define ZL_SETSOCKOPT(a,b,c,d,e)  setsockopt((int)a,(int)b,(int)c,(const void *)d,(int)e)
#define ZL_GETHOSTBYNAME(a)       gethostbyname((const char *)a)
#define ZL_LSEEK(a,b,c)           lseek(a,b,c)
#define ZL_SENDFILE(a,b,c,d)      sendfile(a, b, c, d)

#define ZL_INVALID_SOCKET         -1
#define SEND_FLAGS                0
#define SET_SOCKET_ERROR(x,y)     errno=y
#define SOCKET_ERROR_INTERUPT     EINTR
#define SOCKET_ERROR_TIMEDOUT     EAGAIN

#endif

bool zl_socket_startup();
bool zl_socket_cleanup();
void zl_socket_create();

#endif  /* ZL_SOCKET_H */