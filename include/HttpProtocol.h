// ***********************************************************************
// Filename         : HttpProtocol.h
// Author           : LIZHENG
// Created          : 2014-07-01
// Description      : Http协议定义
//
// Last Modified By : LIZHENG
// Last Modified On : 2014-07-01
// 
// Copyright (c) lizhenghn@gmail.com. All rights reserved.
// ***********************************************************************
#ifndef ZL_HTTPPROTOCOL_H
#define ZL_HTTPPROTOCOL_H
#include "Define.h"

NAMESPACE_ZL_START

#define HTTP_VERSION_1_0      "HTTP/1.0"
#define HTTP_VERSION_1_1      "HTTP/1.1"
#define DEFAULT_HTTP_VERSION  "HTTP/1.1"

enum HttpMethod
{
	HttpHead    = 0,
	HttpGet     = 1,
	HttpPost    = 2,
	HttpPut     = 3,
	HttpDelete  = 4,
	HttpTrace   = 5,
	HttpOptions = 6,
	HttpConnect = 7,
	HttpPatch   = 8,
	HttpMethodNum = 9
};

const static char* const HttpRequestMethodStr[HttpMethod::HttpMethodNum] = {
	"HEAD",      // 0
	"GET",       // 1
	"POST",      // 2
	"PUT",       // 3
	"DELETE",    // 4
	"TRACE",     // 5
	"OPTIONS",   // 6
	"CONNECT",   // 7
	"PATCH"      // 8
};

enum HttpResponseCode
{
    /* 1xx Infomational */
    StatusContinue = 100,
    StatusSwichingProtocols,

    /* 2xx Succesful */
    StatusOk = 200,
    StatsuCreated,
    StatusAccepted,
    StatusNonAuthorizedInformation,
    StatusNoContent,
    StatusResetContent,
    StatusPartialContent,

    /* 3xx Redirection */
    StatusMultipleChoices = 300,
    StatusMovedPermanetly,
    StatusFound,
    StatusSeeOther,
    StatusNotModified,
    StatusUseProxy,
    StatusTemporaryRedirection = 307,

    /* 4xx Client Error */
    StatusBadRequest = 400,
    StatusUnauthorized,
    StatusPaymentRequired,
    StatusForbidden,
    StatusNotFound,
    StatusMethodNotAllowed,
    StatusNotAcceptable,
    StatusProxyAuthenticationRequired,
    StatusRequestTimeOut,
    StatusConflict,
    StatusGone,
    StatusLengthRequired,
    StatusProconditionFailed,
    StatusRequestEntityTooLarge,
    StatusRequestURITooLarge,
    StatusUnsupportedMediaType,
    StatusRequestedRangeNotSatisfiable,
    StatusExpectationFailed,

    /* 5xx Server Error */
    StatusInternalServerError = 500,
    StatusNotImplemented,
    StatusBadGateway,
    StatusServiceUnavaliable,
    StatusGatewayTimeOut,
    StatusHttpVersionNotSupported
};

NAMESPACE_ZL_END

#endif /* ZL_HTTPPROTOCOL_H */