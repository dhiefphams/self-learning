#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>

#define ERROR -1
#define BUFFER 1024

int main(int argc, char **argv) {
  struct sockaddr_in remote_server;
  int sock;
  char input[BUFFER];
  char output[BUFFER];
  int len;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == ERROR) {
    perror("socket");
    return -1;
  }

  remote_server.sin_family = AF_INET;
  // read port from cli
  remote_server.sin_port = htons(atoi(argv[2]));
  // read host name from cli
  remote_server.sin_addr.s_addr = inet_addr(argv[1]);
  bzero(&remote_server.sin_zero, 8);

  // connect socket to remote server
  if ((connect(sock, (struct sockaddr*) &remote_server, sizeof(struct sockaddr_in))) == ERROR) {
    perror("connect");
    return -1;
  }

  // read and write data
  while (1) {
    // read input from terminal
    fgets(input, BUFFER, stdin);
    // send to socket
    send(sock, input, strlen(input), 0);
    // receive data from remote server
    len = recv(sock, output, BUFFER, 0);
    // end of string
    output[len] = '\0';
    printf("[Receive from remote]\t%s\n", output);
  }
  close(sock);
}
