#include "HttpResponse.h"
#include "HttpKeyValue.h"
#include "Utils.h"

using namespace std;

NAMESPACE_ZL_START

static const char DoubleCrLf[] = "\r\n\r\n";
static const char CrLf[] = "\r\n";

HttpResponse::HttpResponse()
{
}
HttpResponse::~HttpResponse()
{
}

bool HttpResponse::Compile()
{
	ZL::HttpKeyValue *ptable = ZL::HttpKeyValue::GetInstancePtr();

    header.clear();

    char status[8];
    sprintf(status, "%d", GetStatusCode());

    /* HttpVer / StatusCode / ReasonPhrase */
    header += GetHttpVersion() + " ";
    header += string(status) + " ";
    header += ptable->GetReasonDesc( GetStatusCode() ) + CrLf;

    /* Server */
    header += "Server:" + GetServerName() + CrLf;

    /* Content-type */
    header += "Content-type:" + GetContentType();

    /* Content-length */
    char contentLength[32];
    sprintf(contentLength, "%ul", GetContentLength());
    header += "Content-length:" + string(contentLength) + CrLf;

    /* Connection */
    header += "Connection:" + GetConnectionType() + CrLf;

    /* CrLf */
    header += CrLf;

	ReadBoby();

    return true;
}

const std::string HttpResponse::GetHeader()
{
    return header;
}

HttpResponseCode HttpResponse::GetStatusCode()
{
    return status;
}
void HttpResponse::SetStatusCode(HttpResponseCode _status)
{
    status = _status;
}

const string& HttpResponse::GetHttpVersion()
{
    return version;
}
void HttpResponse::SetHttpVersion(const std::string& httpver)
{
    version = httpver;
}

const std::string& HttpResponse::GetServerName()
{
    return server;
}
void HttpResponse::SetServerName(const std::string& _server)
{
    server = _server;
}

const std::string& HttpResponse::GetConnectionType()
{
    return connectionType;
}
void HttpResponse::SetConnectionType(const std::string& _connectionType)
{
    connectionType = _connectionType;
}

const std::string& HttpResponse::GetContentType()
{
    return contentType;
}
void HttpResponse::SetContentType(const std::string& _contentType)
{
    contentType = _contentType;
}

const std::string& HttpResponse::GetDocument()
{
    return document;
}
void HttpResponse::SetDocument(const std::string& _document)
{
    document = _document;
}

unsigned long HttpResponse::GetContentLength()
{
    return document.length();
}

void HttpResponse::ReadBoby()
{
	const std::string filepath = "D:\\html\\"+path;
	if (!IsFileExist(filepath.c_str()))
		return ;

	std::string filebuf;
	GetFileData(filepath.c_str(), filebuf);
	SetDocument(filebuf);
}

NAMESPACE_ZL_END