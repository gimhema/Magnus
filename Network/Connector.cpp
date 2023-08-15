#include"Connector.h"

DWORD WINAPI WorkerThread(LPVOID arg);

MagnusConnector::MagnusConnector()
{

}

MagnusConnector::~MagnusConnector()
{

}

int MagnusConnector::ConnectorMain()
{
	int retval;

	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return 1;
	}


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




