#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
//時刻サービスを実現するための関数をしようするために
#include <time.h>
#define SOCKET_ERROR        -1
#define BUFFER_SIZE         100
#define MESSAGE             "This is the message I'm sending back and forth"
#define QUEUE_SIZE          5

int main(int argc, char* argv[])
{
  //時刻サービスのための宣言
  time_t timer;
  struct tm *local;
  //change

  int hSocket,hServerSocket;  /* handle to socket */
  struct hostent* pHostInfo;  /* holds info about a machine */
  struct sockaddr_in Address; /* Internet socket address stuct */
  int nAddressSize=sizeof(struct sockaddr_in);
  char pBuffer[BUFFER_SIZE];
  int nHostPort;
  
  if(argc < 2) {
	printf("\nUsage: server host-port\n");
	return 0;
  } else {
	nHostPort=atoi(argv[1]);
  }
  
  printf("\nStarting server");
  printf("\nMaking socket"); /* make a socket */
  hServerSocket=socket(AF_INET,SOCK_STREAM,0);
  if(hServerSocket == SOCKET_ERROR) {
    printf("\nCould not make a socket\n");
    return 0;
  }
  
  Address.sin_addr.s_addr=INADDR_ANY; /* fill address struct */
  Address.sin_port=htons(nHostPort);
  Address.sin_family=AF_INET;
  
  printf("\nBinding to port %d",nHostPort);    /* bind to a port */
  if(bind(hServerSocket,(struct sockaddr*)&Address,sizeof(Address)) == SOCKET_ERROR) {
    printf("\nCould not connect to host\n");
    return 0;
  }
  
  getsockname( hServerSocket, (struct sockaddr *) &Address,(int *)&nAddressSize); /*  get port number */
  printf("opened socket as fd (%d) on port (%d) for stream i/o\n",hServerSocket, ntohs(Address.sin_port));
  printf("Server\n  sin_family = %d\n sin_addr.s_addr = %d\n sin_port = %d\n"
         ,Address.sin_family, Address.sin_addr.s_addr, ntohs(Address.sin_port));
  
  printf("\nMaking a listen queue of %d elements",QUEUE_SIZE); /* establish listen queue */
  if(listen(hServerSocket,QUEUE_SIZE) == SOCKET_ERROR) {
    printf("\nCould not listen\n");
    return 0;
  }
  
  for(;;) {
    printf("\nWaiting for a connection\n");  /* get the connected socket */
    hSocket=accept(hServerSocket,(struct sockaddr*)&Address,&nAddressSize);
    
    printf("\nGot a connection");
    
    //時刻を取得してpBufferにコピーする
    timer = time(NULL);
    local = localtime(&timer);
    strcpy(pBuffer, asctime(local));
    //change
   
    printf("\nSending Current time to client");
    
    write(hSocket,pBuffer,strlen(pBuffer)+1); /*write what we received back to the server */
    read(hSocket,pBuffer,BUFFER_SIZE);  /* read from socket into buffer */
    
    if(strcmp(pBuffer, asctime(local)) == 0)
      printf("\nThe messages match");
    else
      printf("\nSomething was changed in the message");
    
    printf("\nClosing the socket"); /* close socket */
    if(close(hSocket) == SOCKET_ERROR) {
      printf("\nCould not close socket\n");
      return 0;
    }
  }
}
