#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_TITLE_LENGTH 100
#define SERVER_IP "127.0.0.1"
#define PORT 8080

void displayMenu();
void readServerResponse(int socket);
void sendRequest(int socket, const char *request);

int main() {
    int client_socket;
    struct sockaddr_in server;
    char choice[2]; // For storing user's menu choice
    char buffer[2000];

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(SERVER_IP);
    server.sin_port = htons(PORT);

    if (connect(client_socket, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("Connection failed");
        return 1;
    }

    printf("Connected to server at %s:%d\n", SERVER_IP, PORT);

    while (1) {
        displayMenu();
        fgets(choice, sizeof(choice), stdin);

        switch (choice[0]) {
            case '1':
                sendRequest(client_socket, "1");
                readServerResponse(client_socket);
                break;
            case '2': {
                char query[MAX_TITLE_LENGTH];
                printf("Enter search query: ");
                fgets(query, sizeof(query), stdin);
                query[strcspn(query, "\n")] = '\0'; // Remove newline character
                char request[2000];
                snprintf(request, sizeof(request), "2 %s", query);
                sendRequest(client_socket, request);
                readServerResponse(client_socket);
                break;
            }
            case '3': {
                int bookIndex;
                printf("Enter book index to order: ");
                scanf("%d", &bookIndex);
                getchar(); // Consume newline character left by scanf
                char request[2000];
                snprintf(request, sizeof(request), "3 %d", bookIndex);
                sendRequest(client_socket, request);
                readServerResponse(client_socket);
                break;
            }
            case '4': {
                int bookIndex;
                printf("Enter book index to pay for: ");
                scanf("%d", &bookIndex);
                getchar(); // Consume newline character left by scanf
                char request[2000];
                snprintf(request, sizeof(request), "4 %d", bookIndex);
                sendRequest(client_socket, request);
                readServerResponse(client_socket);
                break;
            }
            case '5':
                sendRequest(client_socket, "5");
                readServerResponse(client_socket);
                close(client_socket);
                printf("Connection closed.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number from 1 to 5.\n");
                break;
        }
    }

    close(client_socket);
    return 0;
}

void displayMenu() {
    printf("\nEnter your choice:\n");
    printf("1. Display catalog\n");
    printf("2. Search for a book\n");
    printf("3. Order a book\n");
    printf("4. Pay for a book\n");
    printf("5. Exit\n");
}

void sendRequest(int socket, const char *request) {
    if (send(socket, request, strlen(request), 0) == -1) {
        perror("Send failed");
        exit(1);
    }
}

void readServerResponse(int socket) {
    char buffer[5000];
    memset(buffer, 0, sizeof(buffer));
    int recv_len = recv(socket, buffer, sizeof(buffer), 0);
    if (recv_len == -1) {
        perror("Receive failed");
        exit(1);
    }
    printf("Server response:\n%s\n", buffer);
}
