#pragma once
#include "stdafx.h"
#include "RL/RLAlgorithm.h"

// TrainOrder로부터 지정받은 옵션을 기반으로 실질적인 훈련을 진행하는 클래스


class Trainer
{
public:
	Trainer();
	~Trainer();

public:
	void Initailize();

	void TrainStart();
	void Train();
	void TrainEnd();

	// RLAlgorithm의 choose_action을 호출, 
	// DQN 이후에 추가할 알고리즘들은, DQN 클래스를 기반으로 메소드를 구현
	void ChooseAction(); 

	// Gym에서 사용되는 reset과 같은기능
	void ResetEnv();

	// 업데이트중인 State를 가져온다.
	void FetchState();

	// Reward를 계산
	void CalcReward();

	// 네트워크를 학습시킨다.
	void Learn();

	// 다음 상태로 이동시킨다.
	void NextState();

	// 하나의 에피소드가 끝나면 업데이트한다.
//	void UpdateEpisode();

public:
	int episodes = 0;
	std::unordered_map<RL_ALGO::_KIND, RLAlgo::RL_Base> algoMap;

};





