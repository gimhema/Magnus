#pragma once

#include "../stdafx.h"

// Magnus에서 학습시킬 게임과 최초로 통신하는 클래스이다.
// 게임과의 연결 상태를 관리한다.
// 게임에서 전송하는 메세지를 최초로 받아오는 클래스이다.



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

class MagnusConnector
{
public:

	MagnusConnector();
	~MagnusConnector();

public:

	// 일단 여기서 로직 전부 쓰고.. 역할에따라 밑에 함수들로 나누고..
	int ConnectorMain();


	void PublishData();


public:

};