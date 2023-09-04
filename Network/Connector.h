#pragma once

#include "../stdafx.h"

// Magnus에서 학습시킬 게임과 최초로 통신하는 클래스이다.
// 게임과의 연결 상태를 관리한다.
// 게임에서 전송하는 메세지를 최초로 받아오는 클래스이다.


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

// 통신용 소켓정보 구조체
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
	char param[MESSAGE_SIZE];
	std::function<void(char*)> Function; // std function member . . . .
	
public:
	void SetParam(char _param[MESSAGE_SIZE]);
	void SetFunction(std::function<void(char*)> _func); // set function member . . . .
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