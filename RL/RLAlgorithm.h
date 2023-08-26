#pragma once
#include "../stdafx.h"
#include "Utility.h"



struct HyperParammter
{
	int NUM_ACTIONS;
	int NUM_STATES;
    int BatchSize;
    float LR;
    float Gamma;
    float Episilo;
    int MemoryCapacity;
    int QNetIteration;
};


namespace NNet
{
    HyperParammter hParam;

	struct Net : torch::nn::Module {

		Net() {
			fc1 = register_module("fc1", torch::nn::Linear(hParam.NUM_STATES, 50));
			fc2 = register_module("fc2", torch::nn::Linear(50, 30));
			out = register_module("out", torch::nn::Linear(30, hParam.NUM_ACTIONS));
		}

		torch::Tensor forward(torch::Tensor x) {
			x = torch::relu(fc1->forward(x));
			x = torch::relu(fc2->forward(x));
			torch::Tensor action_prob = out->forward(x);
			return action_prob;
		}

		torch::nn::Linear fc1{ nullptr }, fc2{ nullptr }, out{ nullptr };

        void clone_weights_from(const NNet::Net& other) {
            torch::autograd::GradMode::set_enabled(false);
            for (size_t i = 0; i < fc1->parameters().size(); ++i) {
                fc1->parameters()[i].data().copy_(other.fc1->parameters()[i].data());
            }
            for (size_t i = 0; i < fc2->parameters().size(); ++i) {
                fc2->parameters()[i].data().copy_(other.fc2->parameters()[i].data());
            }
            for (size_t i = 0; i < out->parameters().size(); ++i) {
                out->parameters()[i].data().copy_(other.out->parameters()[i].data());
            }
            torch::autograd::GradMode::set_enabled(true);
        }
	};
}

namespace RLAlgo
{
    class DQN {

    public:
        HyperParammter hParam;

    public:
        
        DQN() : eval_net(NNet::Net()), target_net(NNet::Net()), optimizer(eval_net.parameters(), torch::optim::AdamOptions(hParam.LR))
        {
            learn_step_counter = 0;
            memory_counter = 0;
            memory = torch::zeros({ hParam.MemoryCapacity, hParam.NUM_STATES * 2 + 2 });

            loss_func = torch::nn::MSELoss();
        }

        int choose_action(torch::Tensor state);

        void store_transition(torch::Tensor state, int action, float reward, torch::Tensor next_state);

        void learn();

    public:
        NNet::Net eval_net, target_net;
        int learn_step_counter;
        int memory_counter;
        torch::Tensor memory;
        torch::optim::Adam optimizer;
        torch::nn::MSELoss loss_func;
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


