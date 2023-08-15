#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WinSock2.h>
#include <stdio.h>
#include <WS2tcpip.h>

#define SERVERPORT 9000
#define BUFSIZE 1024

namespace NET_ERROR
{
	enum _KIND
	{
		SUCESS = 0,
		FAILED_CREATE_SOCKET = 100,
		FAILED_BIND_SOCKET = 101,
		FAILED_LISTEN_SOCKET = 102,
		FAILED_INVALID_SOCKET = 103,
		FAILED_RECV = 104
	};
}