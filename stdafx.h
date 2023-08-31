#pragma once

#pragma comment(lib, "ws2_32.lib")

#define WIN32_LEAN_AND_MEAN

#define NOMINMAX
#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

// Network
#include <Windows.h>
#include <WinSock2.h>
#include <stdio.h>
#include <WS2tcpip.h>

// Std
#include <random>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <functional>

#define SERVERPORT 9000
#define BUFSIZE 1024

// Lib Torch
#include<torch/torch.h>
#include <torch/optim.h>

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

namespace RL_ALGO
{
	enum _KIND
	{
		DQN = 0,
		PPO = 1,
		SAC = 2
	};
}

struct HyperParammter
{
	int NUM_ACTIONS;
	int NUM_STATES;
	int BatchSize;
	float LR;
	float Gamma;
	float Episilo;
	int MemoryCapacity;
	int QNetIteration;
};

