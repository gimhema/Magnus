from server import Server
import gymnasium as gym
import ray
from ray.rllib.algorithms import ppo, dqn, sac

print("IMPORT COMPLETED")

ray.init()
print("Ray Init ! !")

gTrainServer = Server.remote()
gTrainServer.acceptClients.remote()
print("Setup Server")

class UnrealEnv(gym.Env):
    def __init__(self, env_config):
        self.action_space = # <gym.Space>
        self.observation_space = # <gym.Space>
    def reset(self, seed, options):
        return # <obs>, <info>
    def step(self, action):
        # get current state

        # pop from trainServer recvBuffer

        # calc action value 
        
        # push to trainServer sendBuffer

        # get next state and reward from trainServer recvBuffer

        # loop . . . .
        return # <obs>, <reward: float>, <terminated: bool>, <truncated: bool>, <info: dict>

class RayTrainer:
    def __init__(self) -> None:
        self.unreal_env = # UnraelEnv
        pass


# 알고리즘은 파라미터로 설정할수 있어야한다.
algo = ppo.DQN(env=UnrealEnv, config={
    "env_config": {},  # config to pass to env class
})

print("Start Train ! ! !")
while True:
    print(algo.train())
