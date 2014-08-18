#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define BUFSIZE 1024
#define LISTENQ 1024

int main(int argc, char *argv[]) {
  int listen_sock, comm_sock, msg_len, sa_len, cnt, n;
  struct sockaddr_in sa, new_sa;
  char buf[BUFSIZE];

  listen_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  
  memset(&sa, 0, sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_port   = htons(49152);
  sa.sin_addr.s_addr = htonl(INADDR_ANY);

  if(bind(listen_sock, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
    fprintf(stderr, "bind() failure\n");
    exit(1);
  }

  if(listen(listen_sock, LISTENQ) < 0) {
    fprintf(stderr, "listen() failure\n");
    exit(1);
  }
  
  cnt = 1;
  while(1) {
    printf("Waitinf for a client\n");
    sa_len = sizeof(new_sa);
    if((comm_sock = accept(listen_sock, (struct sockaddr *)&new_sa, &sa_len)) < 0){
      fprintf(stderr, "accept() failure\n");
      exit(1);
    }
    printf("Client %d (%s) connected\n", cnt, inet_ntoa(new_sa.sin_addr));
    if((n = recv(comm_sock, buf, sizeof(buf), 0)) > 0){
      buf[n] = '\0';
      msg_len = strlen(buf);
      printf("Client %d: %s\n", cnt, buf);
      if(send(comm_sock, buf, msg_len, 0) != msg_len) {
        fprintf(stderr, "listen() failure\n");
        exit(1);
      }
    }
    close(comm_sock);
    printf("Client %d disconnected\n", cnt);
    ++cnt;
  }
  return 0;
}
