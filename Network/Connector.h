#pragma once

#include "../stdafx.h"

// Magnus���� �н���ų ���Ӱ� ���ʷ� ����ϴ� Ŭ�����̴�.
// ���Ӱ��� ���� ���¸� �����Ѵ�.
// ���ӿ��� �����ϴ� �޼����� ���ʷ� �޾ƿ��� Ŭ�����̴�.


// Unreal Env -> Magnus Server
namespace ENV_MESSAGE
{
	enum _KIND
	{
		ENV_MESSAGE_SET_TRAIN_ORDER,
		ENV_MESSAGE_START_TRAIN,
		ENV_MESSAGE_CURRENT_STATE
	};
}

// ��ſ� �������� ����ü
struct SOCKETINFO
{
	OVERLAPPED overlapped;
	SOCKET socket;
	char buf[BUFSIZE + 1];
	int recvbytes;
	int sendbytes;
	WSABUF wsabuf;
};

struct AgentMessage
{
	int agentID;
	int fID;
	char fParam[MESSAGE_SIZE];
};

class AgentFunction
{
public:
	AgentFunction();
	~AgentFunction();

public:
	std::string param;
	std::function<void(std::string)> Function; // std function member . . . .
	
public:
	void SetParam(std::string _param);
	void SetFunction(std::function<void(std::string)> _func); // set function member . . . .
	void Execute();

};

class MagnusConnector
{
public:

	MagnusConnector();
	~MagnusConnector();

public:
	std::unordered_map<ENV_MESSAGE::_KIND, AgentFunction> agentFunctionMap;


public:

	void ConnectorInitialize();

	int ConnectorMain();

	void ConnectorServerAction();

	void PublishData();


public:

};