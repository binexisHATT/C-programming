#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main() {
	printf("[+] Starting TCP Server...\n");
	int sockfd, insockfd;
	struct sockaddr_in server_addr, client_addr;
	char buffer[100];

	// Create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	// Set the server socket options
	memset(&server_addr, 0, sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(1234);

	// Bind a socket to a port
	bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in));

	// listen for incoming connections
	listen(sockfd, 5);
	int client_len = sizeof(client_addr);

	// Accepting multiple connections
	while (1)
	{
		insockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
		// if fork() returns 0, this is a child process
		if (fork() == 0)
		{
			close(sockfd);

			// Read data
			memset(buffer, 0, sizeof(buffer));
			int len = read(insockfd, buffer, 100);
			printf("Received %d bytes:\n%s\n", len, buffer);
			close(insockfd);
			return 0;
		}
		else // Parent process
		{
			close(insockfd);
		}
	}
	return 0;
}