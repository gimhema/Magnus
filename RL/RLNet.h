#pragma once


// Magnus에서 제공하는 모든 강화학습 네트워크들의 슈퍼클래스

class RLNet
{
public:
	RLNet();
	~RLNet();

public:

};

class DQN : public RLNet
{
public:


public:
	DQN();
	~DQN();
};

class TRPO : public RLNet
{
public:


public:
	TRPO();
	~TRPO();
};

class PPO : public RLNet
{
public:


public:
	PPO();
	~PPO();
};


class SAC : public RLNet
{
public:


public:
	SAC();
	~SAC();
};
