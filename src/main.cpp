#include <iostream>
#include "HttpLog.h"

int main()
{
	ZL::g_httplog.Print("Hello World [%d]\n", 1000);

	return 0;
}