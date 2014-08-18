#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  struct hostent *host;
  uint32_t ip;
  unsigned char *ptr, *addr;
  int i = 0;

  if(argc < 2) {
    fprintf(stderr, "too few arguments\n");
    exit(1);
  }
  
  host = gethostbyname(argv[1]);

  if(host == NULL) {
    fprintf(stderr, "gethostbyname() failure\n");
    exit(1);
  }
  else if(host->h_addrtype != AF_INET) {
    fprintf(stderr, "h_addrtype is not AF_INET\n");
    exit(1);
  }
  
  while((ptr = host->h_addr_list[i++]) != NULL) {
    ip   = ntohl(*((uint32_t *)ptr));
    addr = (char *)&ip;
    printf("%d. %d. %d. %d\n", addr[3], addr[2], addr[1], addr[0]);
  }

  return 0;
}
