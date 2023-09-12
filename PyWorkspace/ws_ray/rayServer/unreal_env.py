import gymnasium as gym
import ray
from ray.rllib.algorithms import ppo, dqn, sac

print("IMPORT COMPLETED")



class UnrealEnv(gym.Env):
    def __init__(self, env_config):
        self.action_space = # <gym.Space>
        self.observation_space = # <gym.Space>
    def reset(self, seed, options):
        return # <obs>, <info>
    def step(self, action):
        return # <obs>, <reward: float>, <terminated: bool>, <truncated: bool>, <info: dict>



class RayTrainer:
    def __init__(self) -> None:
        self.unreal_env = # UnraelEnv
        pass