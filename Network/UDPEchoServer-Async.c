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

int sock;
void IOSignalHandler(int signo);

int main(int argc, char *argv[]) {
  unsigned short servPort;
  struct sockaddr_in servAddr;
  struct sigaction   sigAction;

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
    //printf(".\n");
    sleep(2);
  }

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
