


class UnrealEnvStatus:
    def __init__(self) -> None:
        self.observation_space = {}
        self.choose_action = {}
        self.current_reward = {}
        self.terminated = False
        self.train_report = {
            {}, # current status
            {}, # choose action
            {}, # get reward
            {}  # next status
        }
        pass