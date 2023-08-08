#pragma once
#include "RLEnvironment.h"
#include "RLNet.h"

class MagnusAgent
{

public:
	MagnusAgent();
	~MagnusAgent();

public:
	MagnusRLEnv environment;
	RLNet rlNet;

public:
	void Init();
	void SetEnvironment(MagnusRLEnv _environment);
	void SetRLNetwork(RLNet _rlNet);
};