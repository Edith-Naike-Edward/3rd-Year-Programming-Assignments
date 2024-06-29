import socket
import threading

# Define the process IDs and their corresponding ports
process_addresses = {
    1: ('localhost', 5001),
    2: ('localhost', 5002),
    3: ('localhost', 5003),
    4: ('localhost', 5004)
}

# Function to handle incoming client connections
def handle_client(client_socket, client_address, process_id):
    # Receive the process ID from the client
    request = client_socket.recv(1024).decode()
    print(f"Received process ID {process_id} from {client_address}")

    # Check if the received process ID is the highest
    highest_process_id = max(process_addresses.keys())
    if process_id > highest_process_id:
        print(f"Process {process_id} is the new coordinator")

    # Send the current coordinator process ID to the client
    client_socket.send(str(highest_process_id).encode())

    # Close the client connection
    client_socket.close()

# Function to start the server
def start_server(process_id):
    # Create a socket object
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Bind the socket to the process's port
    server_socket.bind(('localhost', process_addresses[process_id]))

    # Listen for incoming connections
    server_socket.listen(5)
    print(f"Server {process_id} listening on port {process_addresses[process_id]}")

    while True:
        # Accept a client connection
        client_socket, client_address = server_socket.accept()
        print(f"Accepted connection from {client_address}")

        # Create a new thread to handle the client connection
        client_thread = threading.Thread(target=handle_client, args=(client_socket, client_address))
        client_thread.start()

# Start the server for each process
for process_id in process_addresses.keys():
    start_server(process_id)
