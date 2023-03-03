#include "stdafx.h"
#include "CMyIoCompletionPort.h"

int main()
{
	CMyIoCompletionPort iocpServer;
	if (iocpServer.Initialize())
	{
		iocpServer.StartServer();
	}
	return 0;
}

