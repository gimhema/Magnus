#include"Connector.h"

DWORD WINAPI WorkerThread(LPVOID arg);

MagnusConnector::MagnusConnector()
{

}

MagnusConnector::~MagnusConnector()
{

}

DWORD WINAPI WorkerThread(LPVOID arg)
{
	return 0;
}

int MagnusConnector::ConnectorMain()
{
	int retval;

	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return 1;
	}

	// Create Input/Output Completion Port Step
	HANDLE hcp = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
	if (hcp == NULL) return 1;

	SYSTEM_INFO si;
	GetSystemInfo(&si);

	HANDLE hTread;
	for (int i = 0; i < (int)si.dwNumberOfProcessors * 2; ++i) {
		hTread = CreateThread(NULL, 0, WorkerThread, hcp, 0, NULL);
		if (hTread == NULL)
		{
			return 1;
		}
		CloseHandle(hTread);
	}

	// Create Socket Step
	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, 0);
	if (listenSock == INVALID_SOCKET)
	{
		// Error
		return NET_ERROR::FAILED_CREATE_SOCKET;
	}

	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = bind(listenSock, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		// Error
		return NET_ERROR::FAILED_BIND_SOCKET;
	}

	retval = listen(listenSock, SOMAXCONN);
	if (retval == SOCKET_ERROR)
	{
		// Error
		return NET_ERROR::FAILED_LISTEN_SOCKET;
	}

	SOCKET clientSock;
	struct sockaddr_in clientaddr;
	int addrlen;
	DWORD recvbytes, flags;

	int state = NET_ERROR::SUCESS;

	while (1)
	{
		addrlen = sizeof(clientaddr);
		clientSock = accept(listenSock, (struct sockaddr*)&clientaddr, &addrlen);

		if (clientSock == INVALID_SOCKET)
		{
			state = NET_ERROR::FAILED_INVALID_SOCKET;
			break;
		}

		char addr[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &clientaddr.sin_addr, addr, sizeof(addr));
		// Connect Client Successful


		// Connect Client to I/O CompletionPort
		CreateIoCompletionPort((HANDLE)clientSock, hcp, clientSock, 0);

		SOCKETINFO* ptr = new SOCKETINFO;
		if (ptr == NULL)
		{
			state = NET_ERROR::FAILED_INVALID_SOCKET;
			break;
		}

		// Set Socket Information Struct
		memset(&ptr->overlapped, 0, sizeof(ptr->overlapped));
		ptr->socket = clientSock;
		ptr->recvbytes = ptr->sendbytes = 0;
		ptr->wsabuf.buf = ptr->buf;
		ptr->wsabuf.len = BUFSIZE;

		flags = 0;
		retval = WSARecv(clientSock, &ptr->wsabuf, 1, &recvbytes,
			&flags, &ptr->overlapped, NULL);

		if (retval == SOCKET_ERROR) 
		{
			if (WSAGetLastError() != ERROR_IO_PENDING) 
			{
				state = NET_ERROR::FAILED_RECV;
				
			}
			continue;
		}
	}

	// End of Winsock
	WSACleanup();
	return 0;
}


void MagnusConnector::ConnectorSocketInitialize()
{

}

void MagnusConnector::CreateConnectorIOCP()
{
	
}

void MagnusConnector::ConnectorReady()
{

}

void MagnusConnector::ConnectorListen()
{

}

void MagnusConnector::ConnectorClose()
{

}

void MagnusConnector::PublishData()
{

}




