#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include <errno.h>
#include <signal.h>

#define ECHOMAX (255)
#define TIMEOUT (2)

int SendEchoMessage(struct sockaddr_in *pServAddr);
int ReceiveEchoMessage(struct sockaddr_in *pServAddr);
int sock;
void IOSignalHandler(int signo);

int main(int argc, char *argv[]) {
  unsigned short servPort;
  struct sockaddr_in servAddr;
  struct sigaction   sigAction;

  /////////////////////////////////////////////////////
  char *servIP;
  struct sockaddr_in servAddr2;

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

  memset(&servAddr2, 0, sizeof(servAddr2));
  servAddr2.sin_family      = AF_INET;
  servAddr2.sin_addr.s_addr = inet_addr(servIP);
  servAddr2.sin_port        = htons(servPort);  

  maxDescriptor = sock;

  ////////////////////////////////////////////////////////

  memset(&servAddr, 0, sizeof(servAddr));
  servAddr.sin_family      = AF_INET;
  servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servAddr.sin_port        = htons(servPort);

  if(bind(sock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
    fprintf(stderr, "bind() failed\n");
    exit(1);
  }

  sigAction.sa_handler = IOSignalHandler;
 
  if(sigfillset(&sigAction.sa_mask) < 0) {
    fprintf(stderr, "sigfillset() failed\n");
    exit(1);
  }

  sigAction.sa_flags = 0;

  if(sigaction(SIGIO, &sigAction, 0) < 0) {
    fprintf(stderr, "sigaction() failed\n");
    exit(1);
  }

  if(fcntl(sock, F_SETOWN, getpid()) < 0) {
    fprintf(stderr, "Unable to set process owner to us\n");
    exit(1);
  }

  if(fcntl(sock, F_SETFL, O_NONBLOCK | FASYNC) < 0) {
    fprintf(stderr, "Unable to put the sock into nonblocking/async mode\n");
    exit(1);
  }

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
      if(SendEchoMessage(&servAddr2) < 0) {
        break;
      }
    }
    
    if(FD_ISSET(sock, &fdSet)) {
      if(ReceiveEchoMessage(&servAddr2) < 0) {
        break;
      }
    }
  }
  close(sock);
  exit(0);
}

void IOSignalHandler(int signo) {
    struct sockaddr_in clntAddr;
    unsigned int clntAddrLen;
    char msgBuffer[ECHOMAX];
    int recvMsgLen;
    int sendMsgLen;

    do {
      clntAddrLen = sizeof(clntAddr);
      recvMsgLen  = recvfrom(sock, msgBuffer, ECHOMAX, 0,
                             (struct sockaddr *)&clntAddr, &clntAddrLen);
      
      if(recvMsgLen < 0) {
        if(errno != EWOULDBLOCK) {
          fprintf(stderr, "recvfrom() failed\n");
          exit(1);
        }
      } else {
        printf("Handling client %s\n", inet_ntoa(clntAddr.sin_addr));
   
        sendMsgLen = sendto(sock, msgBuffer, recvMsgLen, 0,
                             (struct sockaddr *)&clntAddr, sizeof(clntAddr));
      
        if(recvMsgLen != sendMsgLen) {
          fprintf(stderr, "sendto() sent a differrent number of bytes than expected\n");
          exit(1);
        }
      }
    } while(recvMsgLen >= 0);
}


int SendEchoMessage(struct sockaddr_in *pServAddr) {
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

int ReceiveEchoMessage(struct sockaddr_in *pServAddr) {
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
