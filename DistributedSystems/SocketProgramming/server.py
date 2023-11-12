import socket


def run_server():
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

    # accept incoming connections
    client_socket, client_address = server.accept()
    print(f"Accepted connection from {client_address[0]}:{client_address[1]}")

    # receive data from the client
    while True:
        request = client_socket.recv(1024)
        request = request.decode("utf-8") # convert bytes to string
        
        # if we receive "close" from the client, then we break
        # out of the loop and close the conneciton
        if request.lower() == "close":
            # send response to the client which acknowledges that the
            # connection should be closed and break out of the loop
            client_socket.send("closed".encode("utf-8"))
            break

        print(f"Received: {request}")

        response = "accepted".encode("utf-8") # convert string to bytes
        # convert and send accept response to the client
        client_socket.send(response)

    # close connection socket with the client
    client_socket.close()
    print("Connection to client closed")
    # close server socket
    server.close()


run_server()
#- The code begins by receiving a message from the server using the recv method on the client object.
#   # • The received message is stored in the response variable and is limited to 1024 bytes.
#   # • The decode method is used to convert the received bytes into a string using UTF-8 encoding.
#   # • The code then checks if the server sent the string "closed" by comparing the lowercased response to "closed".
#   # • If the server did send "closed", the break statement is executed, ending the loop and closing the socket.
#   # • If the server did not send "closed", the received message is printed to the console using the print function.
