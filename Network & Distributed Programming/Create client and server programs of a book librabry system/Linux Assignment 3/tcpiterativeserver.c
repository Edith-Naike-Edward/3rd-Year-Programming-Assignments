#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_ISBN_LENGTH 100
#define MAX_PUBLISHER_LENGTH 100
#define MAX_DATE_LENGTH 100
#define PORT 8080

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char authors[MAX_AUTHOR_LENGTH];
    char isbn[MAX_ISBN_LENGTH];
    char publisher[MAX_PUBLISHER_LENGTH];
    char date[MAX_DATE_LENGTH];
    int ordered; // New field to track if the book is ordered
    int paid;    // New field to track if the book is paid
} Book;

int readBooksFromFile(Book books[], const char *filename);
void displayCatalog(const Book books[], int numBooks, char *response);
int searchForItem(const Book books[], int numBooks, const char *query, char *response);
void orderItem(Book books[], int numBooks, int bookIndex, char *response);
void payForItem(Book books[], int numBooks, int bookIndex, char *response);

int main() {
    int server_socket, client_socket, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];
    Book books[MAX_BOOKS];
    int numBooks = readBooksFromFile(books, "Books2.txt");

    if (numBooks == -1) {
        printf("Error reading the book file.\n");
        return 1;
    }

    printf("Initializing socket...\n");
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        return 1;
    }
    printf("Socket created.\n");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("Bind failed");
        return 1;
    }
    printf("Bind done.\n");

    if (listen(server_socket, 10) == -1) {
        perror("Listen failed");
        return 1;
    }
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        printf("Waiting for incoming connections...\n");
        int client_length = sizeof(struct sockaddr_in);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client, (socklen_t*)&client_length)) == -1) {
            perror("Accept failed");
            continue;
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        char response[5000] = "";

        while ((read_size = recv(client_socket, client_message, sizeof(client_message), 0)) > 0) {
            client_message[read_size] = '\0';

            if (strcmp(client_message, "1") == 0) {
                displayCatalog(books, numBooks, response);
            } else if (client_message[0] == '2') {
                char query[MAX_TITLE_LENGTH];
                sscanf(client_message + 2, "%[^\n]", query);
                searchForItem(books, numBooks, query, response);
            } else if (client_message[0] == '3') {
                int bookIndex;
                sscanf(client_message + 2, "%d", &bookIndex);
                orderItem(books, numBooks, bookIndex - 1, response);
            } else if (client_message[0] == '4') {
                int bookIndex;
                sscanf(client_message + 2, "%d", &bookIndex);
                payForItem(books, numBooks, bookIndex - 1, response);
            } else if (strcmp(client_message, "5") == 0) {
                printf("Exit command received from %s:%d. Closing connection.\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
                strcpy(response, "Server shutting down.");
                send(client_socket, response, strlen(response), 0);
                break; // Exit the loop to close connection
            }

            send(client_socket, response, strlen(response), 0);
            memset(client_message, 0, sizeof(client_message));
            memset(response, 0, sizeof(response));
        }

        if (read_size == 0) {
            printf("Client disconnected from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        } else if (read_size == -1) {
            perror("Recv failed");
        }

        close(client_socket);
        printf("Connection closed for %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
    }

    close(server_socket);
    return 0;
}

int readBooksFromFile(Book books[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    int numBooks = 0;
    char line[MAX_TITLE_LENGTH + MAX_AUTHOR_LENGTH + MAX_ISBN_LENGTH + MAX_PUBLISHER_LENGTH + MAX_DATE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^\n]", books[numBooks].title, books[numBooks].authors,
               books[numBooks].isbn, books[numBooks].publisher, books[numBooks].date);
        books[numBooks].ordered = 0; // Initialize ordered field
        books[numBooks].paid = 0;    // Initialize paid field
        numBooks++;
    }

    fclose(file);
    return numBooks;
}

void displayCatalog(const Book books[], int numBooks, char *response) {
    char book_info[5000]; // Increased buffer size to handle longer strings
    strcat(response, "BOOKS CATALOG:\n\n");
    for (int i = 0; i < numBooks; i++) {
        snprintf(book_info, sizeof(book_info), "%d. %s, %s, %s, %s, %s (Ordered: %s, Paid: %s)\n",
                 i + 1, books[i].title, books[i].authors, books[i].isbn, books[i].publisher, books[i].date,
                 books[i].ordered ? "Yes" : "No", books[i].paid ? "Yes" : "No");
        strcat(response, book_info);
    }
}

int searchForItem(const Book books[], int numBooks, const char *query, char *response) {
    char match_info[5000]; // Increased buffer size to handle longer strings
    int matches[MAX_BOOKS];
    int numMatches = 0;

    for (int i = 0; i < numBooks; i++) {
        if (strstr(books[i].title, query) || strstr(books[i].authors, query) || strstr(books[i].publisher, query)) {
            snprintf(match_info, sizeof(match_info), "%d. %s, %s, %s, %s, %s (Ordered: %s, Paid: %s)\n",
                     i + 1, books[i].title, books[i].authors, books[i].isbn, books[i].publisher, books[i].date,
                     books[i].ordered ? "Yes" : "No", books[i].paid ? "Yes" : "No");
            strcat(response, match_info);
            matches[numMatches] = i;
            numMatches++;
        }
    }

    if (numMatches == 0) {
        strcpy(response, "No matches found.\n");
    }

    return numMatches;
}

void orderItem(Book books[], int numBooks, int bookIndex, char *response) {
    if (bookIndex >= 0 && bookIndex < numBooks) {
        if (!books[bookIndex].ordered) {
            books[bookIndex].ordered = 1;
            strcpy(response, "Item ordered successfully.\n");
        } else {
            strcpy(response, "Item already ordered.\n");
        }
    } else {
        strcpy(response, "Invalid book index.\n");
    }
}

void payForItem(Book books[], int numBooks, int bookIndex, char *response) {
    if (bookIndex >= 0 && bookIndex < numBooks) {
        if (books[bookIndex].ordered) {
            if (!books[bookIndex].paid) {
                books[bookIndex].paid = 1;
                strcpy(response, "Item paid successfully.\n");
            } else {
                strcpy(response, "Item already paid.\n");
            }
        } else {
            strcpy(response, "Item not ordered yet.\n");
        }
    } else {
        strcpy(response, "Invalid book index.\n");
    }
}
