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
	ENV_MODE::KIND envMode = ENV_MODE::DEFAULT;

protected:
	virtual void Init(void) = 0;
	virtual void Loop(void) = 0;
	virtual void Action(void) = 0; // Sampling Action Space
	virtual void NextStep(void) = 0;
	virtual void Update(void) = 0;
};

namespace BenchMarkExample
{
	class SimpleSlotMachine : public MagnusRLEnv
	{
	public:
		SimpleSlotMachine();
		~SimpleSlotMachine();
	public:
		virtual void Init();
		virtual void Loop();
		virtual void Action();
		virtual void NextStep();
		virtual void Update();
	};
}


