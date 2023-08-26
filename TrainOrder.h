#pragma once
#include "stdafx.h"

class TrainOrder
{
public:
	TrainOrder();
	~TrainOrder();

public:
	void initialize();

	void SetRLAlgorithm(RL_ALGO::_KIND algo);
	void SetHyperParammeter(HyperParammter param);

public:
	RL_ALGO::_KIND selectedAlgo;
	HyperParammter hParamOption;

};

