import socket
import multiprocessing
import socket
from process import Process
from logicalclock import LamportClock, start_process

def run_server():
    # Function for multiprocessing process
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

    # Main program
if __name__ == "__main__":
        # Call freeze_support to mitigate pickling issue on Windows
        # multiprocessing.freeze_support()

        # Create Lamport clocks for processes
        clock_P = LamportClock()
        clock_Q = LamportClock()

        # Create multiprocessing pipes for communication
        pipe_P, pipe_Q = multiprocessing.Pipe()

        # Create processes P and Q
        process_P_instance = Process("P", clock_P, 5000, pipe_P)
        process_Q_instance = Process("Q", clock_Q, 5001, pipe_Q)

        # Start multiprocessing processes for each process
        process_P = multiprocessing.Process(target=start_process, args=(process_P_instance, pipe_P))
        process_Q = multiprocessing.Process(target=start_process, args=(process_Q_instance, pipe_Q))

        process_P.start()
        process_Q.start()

        # Wait for multiprocessing processes to finish
        process_P.join()
        process_Q.join()

run_server()
