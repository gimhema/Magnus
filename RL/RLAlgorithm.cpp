#include "RLAlgorithm.h"


using namespace RLAlgo;


int DQN::choose_action(torch::Tensor state)
{
    torch::Tensor action_value = eval_net.forward(state);
    if (torch::randn({ 1 }).item<float>() <= hParam.Episilo) { // Greedy policy
        auto action = torch::argmax(action_value).item<int>();
        return action;
    }
    else { // Random policy
        return torch::randint(hParam.NUM_ACTIONS, 1).item<int>();
    }
}

void DQN::store_transition(torch::Tensor state, int action, 
    float reward, torch::Tensor next_state)
{
    torch::Tensor transition = torch::cat({ state, torch::tensor({static_cast<float>(action), reward}), next_state });
    int index = memory_counter % hParam.MemoryCapacity;
    memory[index] = transition;
    memory_counter += 1;
}

void DQN::learn()
{
    if (learn_step_counter % hParam.QNetIteration == 0) {
        target_net.clone_weights_from(eval_net);
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



PPO::PPO()
{

}

PPO::~PPO()
{

}

SAC::SAC()
{

}

SAC::~SAC()
{

}

