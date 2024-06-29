
class VacuumAgent:
    def __init__(self):
        # Initialize the agent's state
        self.location = 'A'
        self.status = {'A': None, 'B': None}

    def perceive(self, location, status):
        # Update the agent's state based on its perception of the environment
        self.location = location
        self.status[location] = status

    def decide(self):
        # Decide what action to take based on the agent's current state
        if self.status[self.location] == 'dirty':
            return 'clean'
        elif self.location == 'A':
            return 'move to B'
        elif self.location == 'B':
            return 'move to A'

    def act(self, action):
        # Carry out the chosen action and update the agent's state accordingly
        if action == 'clean':
            self.status[self.location] = 'clean'
        elif action == 'move to A':
            self.location = 'A'
        elif action == 'move to B':
            self.location = 'B'

    def run(self, environment):
        # Run the agent in the given environment
        for i in range(len(environment)):
            location, status = environment[i]
            self.perceive(location, status)
            action = self.decide()
            self.act(action)
