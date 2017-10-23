#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>

struct sockaddr_in server, client;

int main() {
	int sock, cli;
  int sent;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1  ) {
		perror("socket error");
		return -1;
	}

  // Listening in IPV4
	server.sin_family = AF_INET;
  // port 10000
	server.sin_port = htons(10000);
  // 32 bits
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&server.sin_zero, 8);

	unsigned int len = sizeof(struct sockaddr_in);

	if ((bind(sock, (struct sockaddr*) &server, len)) == -1) {
		perror("bind");
		return -1;
	}

	if ((listen(sock, 5)) == -1) {
		perror("listen");
		return -1;
	}

  char msg[] = "Hello world to socket programming\n";

  // Wait for connection
	while (1) {
		if ((cli = accept(sock, (struct sockaddr*) &client, &len)) == -1) {
			perror("accept");
			return  -1;
		}
    sent = send(cli, msg, strlen(msg), 0);
    printf("Send %d bytes to client: %s\n", sent, inet_ntoa(client.sin_addr));
    close(cli);
	}
	return 0;
}
