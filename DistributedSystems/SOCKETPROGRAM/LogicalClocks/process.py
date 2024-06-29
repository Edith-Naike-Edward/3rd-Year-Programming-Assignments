import time

# Process implementation
class Process:
  def __init__(self, process_name, logical_clock, port, pipe):
      self.process_name = process_name
      self.logical_clock = logical_clock
      self.port = port
      self.pipe = pipe

  def send_message(self, recipient, message):
      recipient_port = recipient.port
      recipient_logical_clock = recipient.receive_message(self, message)
      self.logical_clock.update(recipient_logical_clock)

  def receive_message(self, sender, message):
      sender_port = sender.port
      sender_logical_clock = sender.logical_clock.increment()

      # Simulate message transmission delay
      time.sleep(1)

      print(f"{self.process_name} received message '{message}' from {sender.process_name}")
      self.logical_clock.update(sender_logical_clock)

      return self.logical_clock.value
