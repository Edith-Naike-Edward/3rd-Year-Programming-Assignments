#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

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

    // Create a socket
    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        die("socket");
    }

    memset((char *)&si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);

    if (inet_aton(SERVER, &si_other.sin_addr) == 0) {
        fprintf(stderr, "inet_aton() failed\n");
        close(s);
        exit(1);
    }

    while (1) {
        printf("Enter command: ");
        fgets(message, BUFLEN, stdin);

        // Remove newline character from the end of the input
        message[strcspn(message, "\n")] = 0;

        // Send the command to the server
        if (sendto(s, message, strlen(message), 0, (struct sockaddr *)&si_other, slen) == -1) {
            die("sendto()");
        }

        // Clear the buffer for receiving the response
        memset(buf, '\0', BUFLEN);

        // Try to receive some data from the server
        int recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, &slen);
        if (recv_len == -1) {
            die("recvfrom()");
        }

        // Print the received response
        printf("Server response: \n%s\n", buf);
    }

    close(s);
    return 0;
}
