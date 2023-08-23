#pragma once
#include "../stdafx.h"
#include "Utility.h"

namespace RLSetup
{
	struct RLProperty
	{
		int NUM_ACTIONS;
		int NUM_STATES;
	};
}

namespace NNet
{
	struct NNetSetup
	{
		int BatchSize;
		float LR;
		float Gamma;
		float Episilo;
		int MemoryCapacity;
		int QNetIteration;
	};

	struct Net : torch::nn::Module {

		RLSetup::RLProperty rlInfo;
		NNetSetup netInfo;

		Net() {
			fc1 = register_module("fc1", torch::nn::Linear(rlInfo.NUM_STATES, 50));
			fc2 = register_module("fc2", torch::nn::Linear(50, 30));
			out = register_module("out", torch::nn::Linear(30, rlInfo.NUM_ACTIONS));
		}

		torch::Tensor forward(torch::Tensor x) {
			x = torch::relu(fc1->forward(x));
			x = torch::relu(fc2->forward(x));
			torch::Tensor action_prob = out->forward(x);
			return action_prob;
		}

		torch::nn::Linear fc1{ nullptr }, fc2{ nullptr }, out{ nullptr };
	};
}


namespace RLAlgo
{
	class DQN
	{
	public:
		DQN();
		~DQN();
	};


	class PPO
	{
	public:
		PPO();
		~PPO();
	};


	class SAC
	{
	public:
		SAC();
		~SAC();
	};
}


