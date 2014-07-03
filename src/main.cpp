#include <iostream>
#include "Log.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

void test_log()
{
	ZL::g_httplog.Print("Hello World [%d]\n", 1000);

	INTIALISE_LOG("HttpServer2.log");
	LOG_TRACE("Hello World [%d]", 1000);
	LOG_TRACE("Hello World [%d][%s]", 1000, "ddddert");
}

int main()
{

	return 0;
}