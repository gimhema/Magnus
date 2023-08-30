#pragma once
#include "stdafx.h"
#include "RL/RLAlgorithm.h"

// TrainOrder�κ��� �������� �ɼ��� ������� �������� �Ʒ��� �����ϴ� Ŭ����


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

	// RLAlgorithm�� choose_action�� ȣ��, 
	// DQN ���Ŀ� �߰��� �˰������, DQN Ŭ������ ������� �޼ҵ带 ����
	void ChooseAction(); 

	// Gym���� ���Ǵ� reset�� �������
	void ResetEnv();

	// ������Ʈ���� State�� �����´�.
	void FetchState();

	// Reward�� ���
	void CalcReward();

	// ��Ʈ��ũ�� �н���Ų��.
	void Learn();

	// ���� ���·� �̵���Ų��.
	void NextState();

	// �ϳ��� ���Ǽҵ尡 ������ ������Ʈ�Ѵ�.
//	void UpdateEpisode();

public:
	int episodes = 0;
	std::unordered_map<RL_ALGO::_KIND, RLAlgo::RL_Base> algoMap;

};





