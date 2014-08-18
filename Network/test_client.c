#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>

#define MSGSIZE 512
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  int sock, msg_len, n;
  struct sockaddr_in sa;
  struct hostent *host;
  char msg[MSGSIZE], buf[BUFSIZE];

  if(argc < 2) {
    fprintf(stderr, "too few argument\n");
    exit(1);
  }
  else if(argc > 3) {
    fprintf(stderr, "too many argument\n");
    exit(1);
  }

  host = gethostbyname(argv[1]);
  
  if(host == NULL) {
    fprintf(stderr, "gethostbyname() failuer\n");
    exit(1);
  }
  else if(host->h_addrtype != AF_INET) {
    fprintf(stderr, "h_addrtype is not AF_INET\n");
    exit(1);
  }

  sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

  memset(&sa, 0, sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_port   = htons(80);
  sa.sin_addr.s_addr = *((uint32_t *)(host->h_addr_list[0]));

  if(connect(sock, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
    fprintf(stderr, "connect() failuer\n");
    exit(1);
  }

  if(argc == 2) {
    snprintf(msg, sizeof(msg), 
             "GET / HTTP/1.1\r\nHOST: %s\r\nConnection: close\r\n\r\n",
             argv[1]);
  }
  else if(argc == 3) {
    snprintf(msg, sizeof(msg), 
             "GET / HTTP/1.1\r\nHOST: %s\r\nConnection: close\r\n\r\n",
             argv[2], argv[1]);
  }

  msg_len = strlen(msg);

  if(send(sock, msg, msg_len, 0) != msg_len) {
    fprintf(stderr, "send() failuer\n");
    exit(1);
  }

  while((n = recv(sock, buf, sizeof(buf), 0)) > 0) {
    buf[n] = '\0';
    printf("%s", buf);
  }

  if(n < 0) {
    fprintf(stderr, "recv() failuer\n");
    exit(1);
  }

  printf("\n");
  close(sock);
  
  return 0;
}
