#include "TrainOrder.h"


TrainOrder::TrainOrder()
{

}

TrainOrder::~TrainOrder()
{

}

void TrainOrder::initialize()
{

}

void TrainOrder::SetRLAlgorithm(RL_ALGO::_KIND algo)
{
	selectedAlgo = algo;
}

void TrainOrder::SetHyperParammeter(HyperParammter param)
{
	hParamOption = param;
}






