#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define ECHOMAX (512)

int main(int argc, char *argv[]) {
  unsigned short servPort;
  
  int sock;
  struct sockaddr_in servAddr;
  struct sockaddr_in clntAddr;
  unsigned int clntAddrLen;
  char msgBuffer[ECHOMAX];
  int recvMsgLen;
  int sendMsgLen;
      
  if(argc != 2) {
    fprintf(stderr, "Usage: %s <Echo Port>\n", argv[0]);
    exit(1);
  }

  servPort = atoi(argv[1]);
  sock     = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if(sock < 0) {
    fprintf(stderr, "socket() failed\n");
    exit(1);
  }

  memset(&servAddr, 0, sizeof(servAddr));
  servAddr.sin_family      = AF_INET;
  servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servAddr.sin_port        = htons(servPort);

  if(bind(sock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
    fprintf(stderr, "bind() failed\n");
    exit(1);
  }

  for(;;) {
    clntAddrLen = sizeof(clntAddr);
    recvMsgLen  = recvfrom(sock, msgBuffer, ECHOMAX, 0,
                           (struct sockaddr *)&clntAddr, &clntAddrLen);

    if(recvMsgLen < 0) {
      fprintf(stderr, "recvfrom() failed\n");
      exit(1);
    }

    printf("Handling client %s\n", inet_ntoa(clntAddr.sin_addr));
    
    sendMsgLen = sendto(sock, msgBuffer, recvMsgLen, 0,
                        (struct sockaddr *)&clntAddr, sizeof(clntAddr));

    if(recvMsgLen != sendMsgLen) {
      fprintf(stderr, "sendto() sent a differrent number of bytes than expected\n");
      exit(1);
    }
  }
}
