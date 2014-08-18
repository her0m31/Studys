#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXRECVMSG (255)

int main(int argc, char *argv[]) {
  char *mcastIP;
  unsigned int mcastPort;
  char *sendString;
  unsigned int sendStringLen;
  
  int sock;
  unsigned char mcastTTL;
  struct sockaddr_in mcastAddr;
  int sendMsgLen;
  
  if((argc < 4) || (argc > 5)) {
    fprintf(stderr, "Usage: %s <Multicast IP Address> <Port> <Send String> [<TTL>]\n",
            argv[0]);
    exit(1);
  }

  mcastIP   = argv[1];
  
  mcastPort = atoi(argv[2]);
  
  sendString = argv[3];

  sendStringLen = strlen(sendString);

  if(argc == 5) {
    mcastTTL = atoi(argv[4]);
  }
  else {
    mcastTTL = 1;
  }

  sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if(sock < 0) {
    fprintf(stderr, "socket() failed\n");
    exit(1);
  }

  if(setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, (void*)&mcastTTL, sizeof(mcastTTL)) < 0) {
    fprintf(stderr, "setsockopt() failed\n");
    exit(1);
  }

  memset(&mcastAddr, 0, sizeof(mcastAddr));
  mcastAddr.sin_family      = AF_INET;
  mcastAddr.sin_addr.s_addr = inet_addr(mcastIP);
  mcastAddr.sin_port        = htons(mcastPort);

  sendMsgLen = sendto(sock, sendString, sendStringLen, 0,
                      (struct sockaddr*)&mcastAddr, sizeof(mcastAddr));

  if(sendMsgLen != sendStringLen) {
    fprintf(stderr, "sendto() sent a different number of bytes than expected\n");
    exit(1);
  }

  close(sock);
  
  exit(0);
}
