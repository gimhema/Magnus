#pragma once

#include "../stdafx.h"

// Magnus���� �н���ų ���Ӱ� ���ʷ� ����ϴ� Ŭ�����̴�.
// ���Ӱ��� ���� ���¸� �����Ѵ�.
// ���ӿ��� �����ϴ� �޼����� ���ʷ� �޾ƿ��� Ŭ�����̴�.



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

class MagnusConnector
{
public:

	MagnusConnector();
	~MagnusConnector();

public:

	// �ϴ� ���⼭ ���� ���� ����.. ���ҿ����� �ؿ� �Լ���� ������..
	int ConnectorMain();


	void PublishData();


public:

};