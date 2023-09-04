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
	int functionID;
	char fuctionVal[MESSAGE_SIZE];
};

class MagnusConnector
{
public:

	MagnusConnector();
	~MagnusConnector();

public:

	int ConnectorMain();

	void ConnectorServerAction();

	void PublishData();


public:

};