#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXRECVMSG (255)

int main(int argc, char *argv[]) {
  char *mcastIP;
  unsigned int mcastPort;

  int sock;
  int optVal;
  struct sockaddr_in mcastAddr;
  struct ip_mreq     mcastReq;

  int msgCount;
  struct sockaddr_in fromAddr;
  unsigned int fromAddrLen;
  char msgBuffer[MAXRECVMSG + 1];
  int recvMsgLen;

  if(argc != 3) {
    fprintf(stderr, "Usage: %s <Multicast IP Address> <Multicast Port>\n", argv[0]);
    exit(1);
  }

  mcastIP   = argv[1];
  
  mcastPort = atoi(argv[2]);

  sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if(sock < 0) {
    fprintf(stderr, "socket() failed\n");
    exit(1);
  }

  memset(&mcastAddr, 0, sizeof(mcastAddr));
  mcastAddr.sin_family      = AF_INET;
  mcastAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  mcastAddr.sin_port        = htons(mcastPort);
  
  optVal = 1;
  if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (void*)&optVal, sizeof(optVal)) < 0) {
    fprintf(stderr, "setsockopt() failed\n");
    exit(1);
  }

  if(bind(sock, (struct sockaddr *)&mcastAddr, sizeof(mcastAddr)) < 0) {
    fprintf(stderr, "bind() failed\n");
    exit(1);
  }

  mcastReq.imr_multiaddr.s_addr = inet_addr(mcastIP);
  mcastReq.imr_interface.s_addr = htonl(INADDR_ANY);
  
  if(setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void*)&mcastReq, sizeof(mcastReq)) < 0) {
    fprintf(stderr, "setsockopt() failed\n");
    exit(1);
  }

  for(msgCount = 0; msgCount < 4; msgCount++) {
    fromAddrLen = sizeof(fromAddr);
    recvMsgLen  = recvfrom(sock, msgBuffer, MAXRECVMSG, 0,
                           (struct sockaddr*)&fromAddr, &fromAddrLen);
    if(recvMsgLen < 0) {
      fprintf(stderr, "recvfrom() failed\n");
      exit(1);
    }

    msgBuffer[recvMsgLen] = '\0';

    printf("Received: %s from %s\n", msgBuffer, inet_ntoa(fromAddr.sin_addr));
  }

  close(sock);

  exit(0);
}
