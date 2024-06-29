#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define SERVER "127.0.0.1"
#define PORT 8080
#define BUFLEN 512

void die(char *s) {
    perror(s);
    exit(1);
}

int main() {
    struct sockaddr_in si_other;
    int s, slen = sizeof(si_other);
    char buf[BUFLEN];
    char message[BUFLEN];
    WSADATA wsa;

    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed. Error Code : %d", WSAGetLastError());
        return 1;
    }

    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR) {
        die("socket");
    }

    memset((char*)&si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);
    si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);

        while (1) {
        printf("Enter command: ");
        fgets(message, BUFLEN, stdin);

        // Remove newline character from the end of the input
        message[strcspn(message, "\n")] = 0;

        // Send the command to the server
        if (sendto(s, message, strlen(message), 0, (struct sockaddr*)&si_other, slen) == SOCKET_ERROR) {
            die("sendto()");
        }

        // Clear the buffer for receiving the response
        memset(buf, '\0', BUFLEN);

        // Try to receive some data from the server
        int recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr*)&si_other, &slen);
        if (recv_len == SOCKET_ERROR) {
            die("recvfrom()");
        }

        // Print the received response
        printf("Server response: \n%s\n", buf);
    }

    closesocket(s);
    WSACleanup();

    return 0;
}

