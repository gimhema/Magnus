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

        int choose_action(torch::Tensor state) {
            torch::Tensor action_value = eval_net.forward(state);
            if (torch::randn({ 1 }).item<float>() <= hParam.Episilo) { // Greedy policy
                auto action = torch::argmax(action_value).item<int>();
                return action;
            }
            else { // Random policy
                return torch::randint(hParam.NUM_ACTIONS, 1).item<int>();
            }
        }

        void store_transition(torch::Tensor state, int action, float reward, torch::Tensor next_state) {
            torch::Tensor transition = torch::cat({ state, torch::tensor({static_cast<float>(action), reward}), next_state });
            int index = memory_counter % hParam.MemoryCapacity;
            memory[index] = transition;
            memory_counter += 1;
        }

        void learn() {
            if (learn_step_counter % hParam.QNetIteration == 0) {
//                target_net.load_state_dict(eval_net.state_dict());
            }
            learn_step_counter += 1;

            // Sample a batch from memory
            torch::Tensor sample_index = torch::randint(hParam.MemoryCapacity, { hParam.BatchSize });
            torch::Tensor batch_memory = memory.index_select(0, sample_index);
            torch::Tensor batch_state = batch_memory.slice(1, 0, hParam.NUM_STATES);
            torch::Tensor batch_action = batch_memory.slice(1, hParam.NUM_STATES, hParam.NUM_STATES + 1).to(torch::kLong);
            torch::Tensor batch_reward = batch_memory.slice(1, hParam.NUM_STATES + 1, hParam.NUM_STATES + 2);
            torch::Tensor batch_next_state = batch_memory.slice(1, -hParam.NUM_STATES);

            // Q-value estimation
            torch::Tensor q_eval = eval_net.forward(batch_state).gather(1, batch_action);
            torch::Tensor q_next = target_net.forward(batch_next_state).detach();
            torch::Tensor q_target = batch_reward + hParam.Gamma * std::get<0>(q_next.max(1));
            torch::Tensor loss = loss_func(q_eval, q_target);

            optimizer.zero_grad();
            loss.backward();
            optimizer.step();
        }

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


