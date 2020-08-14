#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define SERVER_IP "192.168.33.138"
#define SERVER_PORT 1234

int main() {
    printf("[+] Running TCP Client Program...\n");

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set the destination server information
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(struct sockaddr_in));
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(SERVER_IP);
    dest.sin_port = htons(SERVER_PORT);

    // Connect to destination server
    connect(sockfd, (struct sockaddr *)&dest, sizeof(struct sockaddr_in));
    // Write data
    char *first_msg = "Hello Server\n";
    char *second_msg = "Hello Again\n";
    write(sockfd, first_msg, strlen(first_msg));
    write(sockfd, second_msg, strlen(second_msg));
    return 0;
}