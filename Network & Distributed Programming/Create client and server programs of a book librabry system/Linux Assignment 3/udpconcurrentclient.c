#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080

int main() {
    struct sockaddr_in server;
    int client_socket;
    char server_response[5000];
    char client_message[2000];

    if ((client_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket creation failed");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Display catalog\n");
        printf("2. Search for a book\n");
        printf("3. Order a book\n");
        printf("4. Pay for a book\n");
        printf("5. Exit\n");

        char choice[10];
        fgets(choice, sizeof(choice), stdin);

        // Remove newline character from choice
        choice[strcspn(choice, "\n")] = 0;

        int send_len = sendto(client_socket, choice, strlen(choice), 0, (struct sockaddr *)&server, sizeof(server));

        if (send_len == -1) {
            perror("Send failed");
            continue;
        }

        if (strcmp(choice, "5") == 0) {
            printf("Exiting client.\n");
            break;
        }

        memset(server_response, 0, sizeof(server_response));
        int recv_len = recvfrom(client_socket, server_response, sizeof(server_response), 0, NULL, NULL);

        if (recv_len == -1) {
            perror("Receive failed");
            continue;
        }

        printf("Server response:\n%s\n", server_response);
    }

    close(client_socket);
    return 0;
}

