#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 8080
#define SERVER "127.0.0.1"

void displayMenu();
void handleServerResponse(SOCKET sock);

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char message[2000];

    printf("\nInitializing Winsock...");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed. Error Code : %d", WSAGetLastError());
        return 1;
    }
    printf("Initialized.\n");

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket: %d", WSAGetLastError());
        return 1;
    }
    printf("Socket created.\n");

    server.sin_addr.s_addr = inet_addr(SERVER);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Connection error");
        return 1;
    }
    printf("Connected to server.\n");

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        sprintf(message, "%d", choice);

        if (choice == 1) {
            send(sock, message, strlen(message), 0);
            handleServerResponse(sock);
        } else if (choice == 2) {
            char query[100];
            printf("Enter the title, author, or publisher to search: ");
            scanf(" %[^\n]", query);
            sprintf(message, "2 %s", query);
            send(sock, message, strlen(message), 0);
            handleServerResponse(sock);
        } else if (choice == 3) {
            int bookIndex;
            printf("Enter the book index to order: ");
            scanf("%d", &bookIndex);
            sprintf(message, "3 %d", bookIndex);
            send(sock, message, strlen(message), 0);
            handleServerResponse(sock);
        } else if (choice == 4) {
            int bookIndex;
            printf("Enter the book index to pay: ");
            scanf("%d", &bookIndex);
            sprintf(message, "4 %d", bookIndex);
            send(sock, message, strlen(message), 0);
            handleServerResponse(sock);
        }
    } while (choice != 5);

    closesocket(sock);
    WSACleanup();
    return 0;
}

void displayMenu() {
    printf("\nChoose an option below:\n");
    printf("1. Display Catalog\n");
    printf("2. Search for Item\n");
    printf("3. Order Item\n");
    printf("4. Pay for Item\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void handleServerResponse(SOCKET sock) {
    char server_reply[5000];
    int read_size;

    if ((read_size = recv(sock, server_reply, 5000, 0)) > 0) {
        server_reply[read_size] = '\0';
        printf("%s\n", server_reply);
    }

    if (read_size == 0) {
        printf("Server disconnected.\n");
    } else if (read_size == -1) {
        printf("recv failed.\n");
    }
}
