#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_TITLE_LENGTH 100
#define SERVER_IP "127.0.0.1"
#define PORT 8080

void menu() {
    printf("Enter your choice:\n");
    printf("1. Display catalog\n");
    printf("2. Search for a book\n");
    printf("3. Order a book\n");
    printf("4. Pay for a book\n");
    printf("5. Exit\n");
}

int main() {
    int client_socket;
    struct sockaddr_in server;
    char server_response[5000];
    char client_message[2000];

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        return 1;
    }

    printf("Socket created.\n");

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to remote server
    if (connect(client_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }

    printf("Connected to server.\n");

    while (1) {
        menu();

        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                strcpy(client_message, "1");
                break;
            case 2: {
                char query[MAX_TITLE_LENGTH];
                printf("Enter search query: ");
                fgets(query, sizeof(query), stdin);
                query[strcspn(query, "\n")] = '\0'; // Remove newline character
                sprintf(client_message, "2 %s", query);
                break;
            }
            case 3: {
                int bookIndex;
                printf("Enter book index to order: ");
                scanf("%d", &bookIndex);
                getchar(); // Clear newline character from input buffer
                sprintf(client_message, "3 %d", bookIndex);
                break;
            }
            case 4: {
                int bookIndex;
                printf("Enter book index to pay for: ");
                scanf("%d", &bookIndex);
                getchar(); // Clear newline character from input buffer
                sprintf(client_message, "4 %d", bookIndex);
                break;
            }
            case 5:
                strcpy(client_message, "5");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                continue;
        }

        // Send message to server
        if (send(client_socket, client_message, strlen(client_message), 0) < 0) {
            perror("Send failed");
            return 1;
        }

        // Receive server response
        if (recv(client_socket, server_response, sizeof(server_response), 0) < 0) {
            perror("Receive failed");
            break;
        }

        printf("Server response:\n%s\n", server_response);

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        memset(server_response, 0, sizeof(server_response));
    }

    close(client_socket);
    return 0;
}
