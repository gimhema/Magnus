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

class EnvConfig():
    def __init__(self) -> None:
        self.config_info_action = None # Action Space
        self.config_info_observation = None # Observation Space
        self.config_info_init_state = None # Init Status when use reset()

        pass
    def LoadEnvConfigFile(self):
        # load config file (.json)

        # set action, observation . . . .
        pass


class UnrealEnv(gym.Env):
    def __init__(self, env_config):
        # Load Config Info
        self.env_config = EnvConfig()
        self.env_config.LoadEnvConfigFile()

        self.action_space = self.env_config.config_info_action
        self.observation_space = self.env_config.config_info_observation
        self.init_status = self.env_config.config_info_init_state

    def reset(self, seed, options):
        return self.init_status, {}
        
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
