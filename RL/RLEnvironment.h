#pragma once

// 강화학습 환경이다. gym의 env와 비슷한 역할을한다.

// 굳이 상속받아서 구현해야할까..? 

namespace ENV_MODE
{
	enum KIND
	{
		DEFAULT,
		TRAIN,
		TEST
	};
}


class MagnusRLEnv
{
public:
	MagnusRLEnv();
	~MagnusRLEnv();


public:
	ENV_MODE::KIND envMode;

public:
	void Init();
	void Loop();
	void Action(); // Sampling Action Space
	void NextStep();
	void Update();



};