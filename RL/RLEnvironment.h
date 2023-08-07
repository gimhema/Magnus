#pragma once

// 강화학습 환경이다. gym의 env와 비슷한 역할을한다.

// Magnus에서 제공하는 모든 강화학습 환경의 슈퍼클래스
class MagnusRLEnv
{
public:
	MagnusRLEnv();
	~MagnusRLEnv();

	void Init();
	void Action();
	void Update();

public:

};