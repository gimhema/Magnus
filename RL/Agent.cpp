#include"Agent.h"



MagnusAgent::MagnusAgent()
{

}

MagnusAgent::~MagnusAgent()
{

}

void MagnusAgent::Init()
{

}


void MagnusAgent::SetEnvironment(MagnusRLEnv _environment)
{
	environment = _environment;
}

void MagnusAgent::SetRLNetwork(RLNet _rlNet)
{
	rlNet = _rlNet;
}




