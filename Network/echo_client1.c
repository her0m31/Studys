#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define MSGSIZE 512
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  int sock, msg_len, n;
  struct sockaddr_in sa;
  char *server_ip;
  char msg[MSGSIZE], buf[BUFSIZE];

  if(argc != 2) {
    fprintf(stderr, "usage: echo_client1 SEVER_IP_ADDRESS\n");
    exit(1);
  }

  server_ip = argv[1];

  sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

  memset(&sa, 0, sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_port   = htons(49152);
  sa.sin_addr.s_addr = inet_addr(server_ip);

  if(connect(sock, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
    fprintf(stderr, "connect() failuer\n");
    exit(1);
  }

  printf("please input a message!\n");
  printf("> ");
  scanf("%s", msg);
  msg_len = strlen(msg);
  
  if(send(sock, msg, msg_len, 0) != msg_len) {
    fprintf(stderr, "send() failuer\n");
    exit(1);
  }
  
  if((n = recv(sock, buf, sizeof(buf), 0)) > 0) {
    buf[n] = '\0';
    printf("Echo message: ");
    printf("%s\n", buf);
  }
  else if(n < 0) {
    fprintf(stderr, "recv() failuer\n");
    exit(1);
  }

  printf("\n");
  close(sock);
  
  return 0;
}
