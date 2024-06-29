import socket

# Process IDs
process_ids = [1, 2, 3, 4]

# Process addresses
process_addresses = {
    1: ('localhost', 5001),
    2: ('localhost', 5002),
    3: ('localhost', 5003),
    4: ('localhost', 5004)
}

# Function to send message to a process
def send_message(process_id, message):
    address = process_addresses[process_id]
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        try:
            s.connect(address)
            s.sendall(message.encode())
        except Exception as e:
            print(f"Error connecting to {address}: {e}")


# Function to receive message from a process
def receive_message(process_id):
    address = process_addresses[process_id]
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind(address)
        s.listen()
        conn, _ = s.accept()
        data = conn.recv(1024).decode()
        return data

# Bully algorithm logic
def bully_algorithm(process_id):
    print(f"Process {process_id} started the election.")

    # Send election message to higher priority processes
    for higher_id in process_ids[process_id:]:
        if higher_id != process_id:
            send_message(higher_id, "ELECTION")

    # Wait for responses from higher priority processes
    for higher_id in process_ids[process_id:]:
        if higher_id != process_id:
            response = receive_message(higher_id)
            if response == "OK":
                print(f"Process {higher_id} is alive.")
                return

    # If no response received, declare self as coordinator
    print(f"Process {process_id} is the coordinator.")

# Test the bully algorithm for process 1
bully_algorithm(1)
