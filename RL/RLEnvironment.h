#pragma once

// ��ȭ�н� ȯ���̴�. gym�� env�� ����� �������Ѵ�.

// ���� ��ӹ޾Ƽ� �����ؾ��ұ�..? 

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