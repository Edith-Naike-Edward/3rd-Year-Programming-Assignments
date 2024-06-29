
import random

class VacuumAgent:
    def __init__(self):
        self.location = random.choice(["A", "B"])
        self.status = random.choice(["clean", "dirty"])
        self.performance = 0

    def move(self, new_location):
        self.location = new_location

    def clean(self):
        self.status = "clean"
        self.performance += 1

    def perceive(self):
        return self.status

    def decide(self):
        current_status = self.perceive()
        if current_status == "dirty":
            self.clean()
        else:
            new_location = "A" if self.location == "B" else "B"
            self.move(new_location)
            self.perceive()

agent = VacuumAgent()

for i in range(10):
    agent.decide()
    print(f"Performance after iteration {i+1}: {agent.performance}")
