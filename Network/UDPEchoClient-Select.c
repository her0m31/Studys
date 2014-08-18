#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define ECHOMAX (255)
#define TIMEOUT (2)

int SendEchoMessage(int sock, struct sockaddr_in *pServAddr);
int ReceiveEchoMessage(int sock, struct sockaddr_in *pServAddr);

int main(int argc, char *argv[]) {
  char *servIP;
  unsigned short servPort;
  
  int sock;
  struct sockaddr_in servAddr;

  int maxDescriptor;
  fd_set fdSet;
  struct timeval tout;
  
  if((argc < 2) || (argc > 3)) {
    fprintf(stderr, "Usage: %s <Server IP> [<Echo Port>]\n", argv[0]);
    exit(1);
  }

  servIP = argv[1];
  
  if(argc == 3) {
    servPort = atoi(argv[2]);
  }
  else {
    servPort = 7;
  }

  sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if(sock < 0) {
    fprintf(stderr, "socket() failed\n");
    exit(1);
  }


  memset(&servAddr, 0, sizeof(servAddr));
  servAddr.sin_family      = AF_INET;
  servAddr.sin_addr.s_addr = inet_addr(servIP);
  servAddr.sin_port        = htons(servPort);  

  maxDescriptor = sock;

  for(;;) {
    FD_ZERO(&fdSet);
    FD_SET(STDIN_FILENO, &fdSet);
    FD_SET(sock, &fdSet);

    tout.tv_sec  = TIMEOUT;
    tout.tv_usec = 0;

    if(select(maxDescriptor +1, &fdSet, NULL, NULL, &tout) == 0) {
      //printf(".\n");
      continue;
    }
    
    if(FD_ISSET(STDIN_FILENO, &fdSet)) {
      if(SendEchoMessage(sock, &servAddr) < 0) {
        break;
      }
    }
    
    if(FD_ISSET(sock, &fdSet)) {
      if(ReceiveEchoMessage(sock, &servAddr) < 0) {
        break;
      }
    }
  }
  
  close(sock);
  exit(0);
}

int SendEchoMessage(int sock, struct sockaddr_in *pServAddr) {
  char echoString[ECHOMAX + 1];
  int  echoStringLen;
  int  sendMsgLen;

  if(fgets(echoString, ECHOMAX +1, stdin) == NULL) {
    return -1;
  }

  echoStringLen = strlen(echoString);
  if(echoStringLen < 1 ) {
    fprintf(stderr, "No input string.\n");
    return -1;
  }

  sendMsgLen = sendto(sock, echoString, echoStringLen, 0,
                      (struct sockaddr*)pServAddr, sizeof(*pServAddr));

  if(echoStringLen != sendMsgLen) {
    fprintf(stderr, "sendto() sent a different number of bytes than expected\n");
    return -1;
  }
  
  return 0;
}

int ReceiveEchoMessage(int sock, struct sockaddr_in *pServAddr) {
  struct sockaddr_in fromAddr;
  unsigned int fromAddrLen;
  char msgBuffer[ECHOMAX +1];
  int recvMsgLen;

  fromAddrLen = sizeof(fromAddr);

  recvMsgLen  = recvfrom(sock, msgBuffer, ECHOMAX, 0, 
                         (struct sockaddr *)&fromAddr, &fromAddrLen);

  if(recvMsgLen < 0) {
    fprintf(stderr, "recvfrom() failed\n");
    return -1;
  }

  if(fromAddr.sin_addr.s_addr != pServAddr->sin_addr.s_addr) {
    fprintf(stderr, "Error: received a packet from unknown source.\n");
    return -1;
  }

  msgBuffer[recvMsgLen] = '\0';
  printf("Received: %s\n", msgBuffer);

  return 0;
}
