import socket
import multiprocessing
import time

def start_process(process_instance, pipe):
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        process_instance.port = 8000
        server_socket.bind(('localhost', process_instance.port))
        server_socket.listen(1)

        while True:
            client_socket, _ = server_socket.accept()
            message = client_socket.recv(1024).decode('utf-8')

            # Simulate processing the received message
            process_instance.receive_message(None, message)

            # Handle user input and send message to the server
            msg = input("Enter message: ")
            client_socket.send(msg.encode("utf-8")[:1024])

            # Receive response from the server
            response = client_socket.recv(1024)
            response = response.decode("utf-8")
            print(f"{process_instance.process_name} received response: {response}")
            # close connection socket with the client
            client_socket.close()
        print("Connection to client closed")
        # close server socket
        server_socket.close()

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

              
