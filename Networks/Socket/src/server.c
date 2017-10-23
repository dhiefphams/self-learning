#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#define ERROR -1
#define BUFFER 1024
#define MAX_CLIENT 2

int main(int argc, char **argv) {
  struct sockaddr_in server, client;
  // define two socket file descriptor
  int sock, cli;
  int sent;
  // create socket file description
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == ERROR) {
    perror("socket");
    return -1;
  }

  unsigned int sockaddr_len = sizeof(struct sockaddr_in);
  // create server
  server.sin_family = AF_INET;
  // read port from cli
  server.sin_port = htons(atoi(argv[1]));
  server.sin_addr.s_addr = INADDR_ANY;
  bzero(&server.sin_zero, 8);
  // bind sock to server
  if ((bind(sock, (struct sockaddr *) &server, sockaddr_len)) == ERROR) {
    perror("bind");
    return -1;
  }

  // client listen
  if ((listen(sock, MAX_CLIENT)) == ERROR) {
    perror("listen");
    return -1;
  }

  int data_len;
  char data[BUFFER];

  // wait for connection
  while (1) {
    if ((cli = accept(sock, (struct sockaddr *) & client, &sockaddr_len)) == ERROR) {
      perror("accept");
      return -1;
    }

    printf("New client connected from port %d and IP %s\n",
      ntohs(client.sin_port),
      inet_ntoa(client.sin_addr)
    );
    data_len = 1;
    while (data_len) {
      // receive data from socket
      data_len = recv(cli, data, BUFFER, 0);
      if (data_len) {
        // send back to socket
        send(cli, data, data_len, 0);
        data[data_len] = '\0';
        printf("Message sent: %s\n", data);
      }
    }
    printf("Client disconnect\n");
    close(cli);
  }
}