#include "stdafx.h"
#include "Network/Connector.h"



int main()
{
//	std::cout << "Magnus Git Managerment Start . . . . ." << std::endl;
//	at::Tensor tensor = torch::rand({ 2,3 });
//	std::cout << tensor << std::endl;

	MagnusConnector conn;
	conn.ConnectorInitialize();
	conn.ConnectorMain();
	return 0;
}