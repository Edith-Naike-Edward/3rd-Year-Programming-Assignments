import multiprocessing
import random
import time
import client
import server

def process_P(clock, queue):
    while True:
        # Increment the logical clock of process P
        clock.value += 1
        print(f"Process P: Logical clock = {clock.value}")

        # Send a message to process Q
        queue.put(clock.value)

        # Wait for a random time before sending the next message
        time.sleep(random.uniform(0.5, 1.5))

def process_Q(clock, queue):
    while True:
        # Increment the logical clock of process Q
        clock.value += 1
        print(f"Process Q: Logical clock = {clock.value}")

        # Send a message to process P
        queue.put(clock.value)

        # Wait for a random time before sending the next message
        time.sleep(random.uniform(0.5, 1.5))

def main():
    # Create a shared logical clock using a multiprocessing Value
    clock = multiprocessing.Value('i', 0)

    # Create a multiprocessing Queue for message passing between processes
    queue = multiprocessing.Queue()

    # Create process P
    p = multiprocessing.Process(target=process_P, args=(clock, queue))
    p.start()

    # Create process Q
    q = multiprocessing.Process(target=process_Q, args=(clock, queue))
    q.start()

    # Main process receives messages and updates the logical clock
    while True:
        message = queue.get()

        # Update the logical clock of the main process
        clock.value = max(clock.value, message) + 1
        print(f"Main Process: Logical clock = {clock.value}")

if __name__ == '__main__':
    main()


import socket
import multiprocessing
import time

# Logical clock process P
def process_P(logical_clock):
    while True:
        time.sleep(1)  # Increment the logical clock every second
        logical_clock.value += 1

# Logical clock process Q
def process_Q(logical_clock):
    while True:
        time.sleep(2)  # Increment the logical clock every two seconds
        logical_clock.value += 1

def run_server():
    # Create a shared logical clock variable
    logical_clock = multiprocessing.Value('i', 0)

    # Start process P
    process_p = multiprocessing.Process(target=process_P, args=(logical_clock,))
    process_p.start()

    # Start process Q
    process_q = multiprocessing.Process(target=process_Q, args=(logical_clock,))
    process_q.start()

    #1. create a server object
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    #The first argument (socket.AF_INET) specifies the IP address family for IPv4 and 
    #the second argument (socket.SOCK_STREAM) indicates that we are using a TCP socket.

    #2. binding server socket to IP address and port
    #Define the hostname or server IP and port to indicate the address which the server
    #will be reachable from and where it will listen for incoming connections.
    server_ip = "127.0.0.1"
    port = 8000

    #The port variable is set to 8000, which is the port number that the server
    #application will be identified by by the operating system
    # bind the socket to a specific address and port
    server.bind((server_ip, port))
    # listen for incoming connections
    server.listen(0)
    print(f"Listening on {server_ip}:{port}")

    while True:
        # accept incoming connections
        client_socket, client_address = server.accept()
        print(f"Accepted connection from {client_address[0]}:{client_address[1]}")

        # receive data from the client
        while True:
            request = client_socket.recv(1024)
            request = request.decode("utf-8") # convert bytes to string
            
            # if we receive "close" from the client, then we break
            # out of the loop and close the connection
            if request.lower() == "close":
                # send response to the client which acknowledges that the
                # connection should be closed and break out of the loop
                client_socket.send("closed".encode("utf-8"))
                break

            print(f"Received: {request}")

            # Get the current value of the logical clock
            current_logical_clock = logical_clock.value

            response = f"accepted (Logical Clock: {current_logical_clock})".encode("utf-8") # convert string to bytes
            # convert and send accept response to the client
            client_socket.send(response)

        # close connection socket with the client
        client_socket.close()
        print("Connection to client closed")

    # close server socket
    server.close()

    # Terminate the processes
    process_p.terminate()
    process_q.terminate()


run_server()
#- The code begins by receiving a message from the server using the recv method on the client object.
#   # • The received message is stored in the response variable and is limited to 1024 bytes.
#   # • The decode method is used to convert the received bytes into a string using UTF-8 encoding.
#   # • The code then checks if the server sent the string "closed" by comparing the lowercased response to "closed".
#   # • If the server did send "closed", the break statement is executed, ending the loop and closing the socket.
#   # • If the server did not send "closed", the received message is printed to the console using the print function.


