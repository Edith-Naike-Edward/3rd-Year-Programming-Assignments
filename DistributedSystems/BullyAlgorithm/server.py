import socket
import threading


def process(self, process_id, processes):
  # send election message to all processes with higher process_id
  self.process_id = process_id
  self.processes = processes
  self.isCoordinator = False
  self.isInitiator = False

i = 0
num_processes = 4

def election(self, process_id, processes):
  print(f"Process {process_id} is sending election message to all processes with higher process_id")
  
  # Set the initiator process ID
  initiator_process_id = 2

  # Start the election if the current process is the initiator
  if initiator_process_id == self.process_id:
    election(initiator_process_id, self.processes)
  for process in processes:
    if process > initiator_process_id:
      # Send election message to process
      # print(f"Process {process_id} is sending election message to process {process}")
      # Receive OK message from process
      print(f"Process {process_id} received OK message from process {process}")
      for i in range(len(num_processes) - 1):
        if process_id[i] > process_id[i + 1]:
          # Send I won message to process
          print(f"Process {process_id} is sending I won message to process {process}")
        else:
          # The process sends I won message to process
          print(f"Process {process_id} received I won message from process {process}")
  self.isCoordinator = True
  print(f"Process {process_id} is the coordinator")
  

def handle_client(client_socket, client_address):
  connected = True
  while connected:

def main():
  server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  server_ip = "127.0.0.1"
  port = 8000
  server.bind((server_ip, port))
  # listen for incoming connections
  server.listen(0)
  print(f"Listening on {server_ip}:{port}")

  while True:
    # accept incoming connections
    client_socket, client_address = server.accept()
    thread = threading.Thread(target=handle_client, args=(client_socket, client_address))
    print(f"Accepted connection from {client_address[0]}:{client_address[1]}")
    thread.start()

if __name__ == "__main__":
  main()
