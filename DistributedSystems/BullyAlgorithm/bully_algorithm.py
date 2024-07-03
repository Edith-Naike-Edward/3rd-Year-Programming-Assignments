import socket
import threading
import time

# Function to simulate a process in the distributed system
def process(process_id, priority, processes):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('127.0.0.1', processes[process_id]['port']))
    server_socket.listen()

    while True:
        connection, address = server_socket.accept()
        data = connection.recv(1024).decode('utf-8')

        if data == 'ELECTION':
            election(process_id, priority, processes)
        elif data == 'COORDINATOR':
            print(f"Process {process_id} received COORDINATOR message. It is the new leader.")
        else:
            print(f"Process {process_id} received unknown message: {data}")

        connection.close()

# Function to initiate an election
def election(process_id, priority, processes):
    print(f"Process {process_id} initiates election.")

    higher_processes = [pid for pid, info in processes.items() if info['priority'] > priority]
    for higher_pid in higher_processes:
        try:
            client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            client_socket.connect(('127.0.0.1', processes[higher_pid]['port']))
            client_socket.send('ELECTION'.encode('utf-8'))
            client_socket.close()
        except:
            pass  # Ignore connection errors

    time.sleep(1)  # Wait for election messages to propagate

    if not higher_processes:
        # No higher-priority processes, declare itself as the leader
        print(f"Process {process_id} is the new leader.")
        announce_leader(process_id, processes)

# Function to announce the leader
def announce_leader(process_id, processes):
    for pid, info in processes.items():
        if pid != process_id:
            try:
                client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                client_socket.connect(('127.0.0.1', info['port']))
                client_socket.send('COORDINATOR'.encode('utf-8'))
                client_socket.close()
            except:
                pass  # Ignore connection errors

if __name__ == "__main__":
    # Define processes with unique IDs, priorities, and ports
    processes = {
    1: {'priority': 2, 'port': 6001},
    2: {'priority': 1, 'port': 6002},
    3: {'priority': 3, 'port': 6003},
    4: {'priority': 4, 'port': 6004},
    }


    # Create threads for each process
    threads = []
    for process_id in processes:
        thread = threading.Thread(target=process, args=(process_id, processes[process_id]['priority'], processes))
        thread.start()
        threads.append(thread)

    # Wait for all threads to finish
    for thread in threads:
        thread.join()
