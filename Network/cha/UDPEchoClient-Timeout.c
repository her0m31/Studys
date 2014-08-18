#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define ECHOMAX      (512)
#define TIMEOUT_SECS (2)
#define MAXTRIES     (5)

int tries = 0;
void AlarmSignalHandler(int signo);

int main(int argc, char *argv[]) {
  char *servIP;
  char *echoString;
  int  echoStringLen;
  unsigned short servPort;
  
  int sock;
  struct sigaction   sigAction;
  struct sockaddr_in servAddr;

  int sendMsgLen;
  struct sockaddr_in fromAddr;
  unsigned int fromAddrLen;
  char msgBuffer[ECHOMAX+1];
  int recvMsgLen;
  
  if((argc < 3) || (argc > 4)) {
    fprintf(stderr, "Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
    exit(1);
  }

  servIP = argv[1];
  
  echoString = argv[2];

  echoStringLen = strlen(echoString);
  if(echoStringLen > ECHOMAX) {
    fprintf(stderr, "Echo word too loong\n");
    exit(1);
  }

  if(argc == 4) {
    servPort = atoi(argv[3]);
  }
  else {
    servPort = 7;
  }
  
  sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if(sock < 0) {
    fprintf(stderr, "socket() failed\n");
    exit(1);
  }

  sigAction.sa_handler = AlarmSignalHandler;

  if(sigfillset(&sigAction.sa_mask) < 0) {
    fprintf(stderr, "sigfillset() failed\n");
    exit(1);
  }

  sigAction.sa_flags = 0;

  if(sigaction(SIGALRM, &sigAction, 0) < 0) {
    fprintf(stderr, "sigaction() failed\n");
    exit(1);
  }

  memset(&servAddr, 0, sizeof(servAddr));
  servAddr.sin_family      = AF_INET;
  servAddr.sin_addr.s_addr = inet_addr(servIP);
  servAddr.sin_port        = htons(servPort);  

  sendMsgLen = sendto(sock, echoString, echoStringLen, 0,
                      (struct sockaddr*)&servAddr, sizeof(servAddr));
  
  if(echoStringLen != sendMsgLen) {
    fprintf(stderr, "sendto() sent a different number of bytes than expected\n");
    exit(1);
  }

  alarm(TIMEOUT_SECS);

  fromAddrLen = sizeof(fromAddr);
  recvMsgLen  = recvfrom(sock, msgBuffer, ECHOMAX, 0,
                         (struct sockaddr *)&fromAddr, &fromAddrLen);

  while(recvMsgLen < 0) {
    if(errno != EINTR) {
      fprintf(stderr, "recvfrom() failed\n");
      exit(1);
    }

    printf("time out: %d\n", tries);
    
    if(tries >= MAXTRIES) {
      fprintf(stderr, "No Response\n");
      exit(1);
    }

    sendMsgLen = sendto(sock, echoString, echoStringLen, 0,
                        (struct sockaddr *)&servAddr, sizeof(servAddr));

    if(echoStringLen != sendMsgLen) {
      fprintf(stderr, "sendto() sent a different number of bytes than expected\n");
      exit(1);
    }

    alarm(TIMEOUT_SECS);

    fromAddrLen = sizeof(fromAddr);
    recvMsgLen  = recvfrom(sock, msgBuffer, ECHOMAX, 0,
                           (struct sockaddr *)&fromAddr, &fromAddrLen);
  }

  alarm(0);

  if(recvMsgLen != echoStringLen) {
    fprintf(stderr, "recvfrom() failed\n");
    exit(1);
  }

  if(fromAddr.sin_addr.s_addr != servAddr.sin_addr.s_addr) {
    fprintf(stderr, "Error: received a packet from unknown source\n");
    exit(1);
  }
  
  msgBuffer[recvMsgLen] = '\0';
  printf("Received: %s\n", msgBuffer);

  close(sock);
  exit(0);
}

void AlarmSignalHandler(int signo) {
  tries += 1;
}
