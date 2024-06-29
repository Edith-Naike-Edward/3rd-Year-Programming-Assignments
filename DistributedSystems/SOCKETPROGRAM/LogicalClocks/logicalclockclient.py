import socket
import multiprocessing
import time
from logicalclockserver import start_process
from logicalclock import process_instance

def run_client():
  #create a socket object
  client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  server_ip = "localhost"
  server_port = process_instance.port  # Use the same port as the server
  client.connect((server_ip, server_port))
  #create a loop to send and receive messages
  while True:

      # Lamport logical clock implementation
      class LamportClock:
          def __init__(self):
              self.value = 0
              self.lock = multiprocessing.Lock()

          def increment(self):
              with self.lock:
                  self.value += 1
                  return self.value

          def update(self, received_time):
              with self.lock:
                  self.value = max(self.value, received_time) + 1
                  return self.value
              
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

        #freeing resources (close client socket)
  # close client socket (connection to the server)
  client.close()
  print("Connection to server closed")
run_client()

      
