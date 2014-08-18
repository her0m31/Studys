#include <stdio.h>
#include <netinet/in.h>

int main() {
  uint32_t value     = 0x01020304;
  unsigned char *ptr = (char *)&value;

  printf("Host byte order: %x %x %x %x\n", ptr[0] , ptr[1], ptr[2], ptr[3]);
  value = htonl(value);
  printf("Network byte order: %x %x %x %x\n", ptr[0] , ptr[1], ptr[2], ptr[3]);
 
  value = ntohl(value);
  printf("RE: Host byte order: %x %x %x %x\n", ptr[0] , ptr[1], ptr[2], ptr[3]);
 
  return 0;
}
