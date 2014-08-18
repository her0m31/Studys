#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define SOCKET_ERROR        -1
#define BUFFER_SIZE         100
#define HOST_NAME_SIZE      255

int  main(int argc, char* argv[])
{
    int hSocket;                 /* handle to socket */
    struct hostent* pHostInfo;   /* holds info about a machine */
    struct sockaddr_in Address;  /* Internet socket address stuct */
    long nHostAddress;
    char pBuffer[BUFFER_SIZE];
    unsigned nReadAmount;
    char strHostName[HOST_NAME_SIZE];
    int nHostPort;

    if(argc < 3) {
	printf("\nUsage: client host-name host-port\n");
	return 0;
    } else {
	strcpy(strHostName,argv[1]);
	nHostPort=atoi(argv[2]);
    }

    printf("\nMaking a socket"); /* make a socket */
    hSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(hSocket == SOCKET_ERROR) {
        printf("\nCould not make a socket\n");
        return 0;
    }

    pHostInfo=gethostbyname(strHostName);  /* get IP address from name */
    memcpy(&nHostAddress,pHostInfo->h_addr,pHostInfo->h_length); /* copy address into long */

    Address.sin_addr.s_addr=nHostAddress;  /* fill address struct */
    Address.sin_port=htons(nHostPort);
    Address.sin_family=AF_INET;

    printf("\nConnecting to %s on port %d\n",strHostName,nHostPort);
    if(connect(hSocket,(struct sockaddr*)&Address,sizeof(Address)) == SOCKET_ERROR) { /* connect to host */
        printf("\nCould not connect to host\n");
        return 0;
    }

    nReadAmount=read(hSocket,pBuffer,BUFFER_SIZE); /* read from socket into buffer*/
    printf("\nCurrent time is %s",pBuffer);
   
    write(hSocket, pBuffer, nReadAmount);  /* write what we received back to server */
    printf("\nWriting Current time to server");

    printf("\nClosing socket\n"); /* close socket */
    if(close(hSocket) == SOCKET_ERROR) {  
        printf("\nCould not close socket\n");
        return 0;
    }
}
