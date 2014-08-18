#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <pthread.h>

#define BUFSIZE 1024
#define LISTENQ 1024

void *thread(void *arg);

struct ThreadArgs {
  int sock;
  int cnt;
  struct sockaddr_in sa;
};

int main(int argc, char *argv[]) {
  int listen_sock, comm_sock, sa_len, cnt, n;
  struct sockaddr_in sa, new_sa;
  pthread_t thread_id;
  struct ThreadArgs *args;

  listen_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  
  memset(&sa, 0, sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_port   = htons(49152);
  sa.sin_addr.s_addr = htonl(INADDR_ANY);

  if(bind(listen_sock, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
    fprintf(stderr, "bind() failure\n");
    exit(1);
  }

  if(listen(listen_sock, LISTENQ) < 0) {
    fprintf(stderr, "listen() failure\n");
    exit(1);
  }
  
  cnt = 0;
  while(1) {
    printf("Waitinf for a client\n");
    sa_len = sizeof(new_sa);
    if((comm_sock = accept(listen_sock, (struct sockaddr *)&new_sa, &sa_len)) < 0){
      fprintf(stderr, "accept() failure\n");
      exit(1);
    }
    ++cnt;
    //引数用の構造体をmalloc()によって確保
    args = (struct ThreadArgs *)malloc(sizeof(struct ThreadArgs));
    //malloc()がメモリの確保に失敗した場合にエラーメッセージを表示
    if(args == NULL) {
      fprintf(stderr, "malloc() failure\n");
      //エラー時に終了する
      exit(1); 
    }
    args->sock =  comm_sock;  //通信用のソケットディスクリプタをセット
    args->cnt  =  cnt;　　　　//クライアント番号をセット
    args->sa   =  sa;         //通信相手の情報が入った構造体をセット
    
    /*
      スレッドidと生成されたスレッドの処理を記述した関数と
      上で情報をセットした構造体を引数にスレッドを生成
    */
    if(pthread_create(&thread_id, NULL, (void *)thread, (void *)args) != 0) {
      //生成に失敗した場合はエラーメッセージを表示
      fprintf(stderr, "pthread_create() failure\n");
      //エラー時に終了する
      exit(1);
    }
  }
  return 0;
}

void *thread(void *arg) {
  int sock, cnt, n, msg_len;
  struct sockaddr_in sa;
  char buf[BUFSIZE];

  //呼び出しスレッドのIDを引数にデタッチする
  pthread_detach(pthread_self());    
  //引数からソケットディスクリプタを取得ローカルのsockにセット
  sock = ((struct ThreadArgs *)arg)->sock;
  //クライアント番号を取得ローカルのcntにセット
  cnt  = ((struct ThreadArgs *)arg)->cnt;  
  //アドレス構造体を取得ローカルのsaにセット
  sa   = ((struct ThreadArgs *)arg)->sa;

  printf("Client %d (%s) connected\n", cnt, inet_ntoa(sa.sin_addr));
  if((n = recv(sock, buf, sizeof(buf), 0)) > 0){
    buf[n] = '\0';
    msg_len = strlen(buf);
    printf("Client %d: %s\n", cnt, buf);
    if(send(sock, buf, msg_len, 0) != msg_len) {
      fprintf(stderr, "listen() failure\n");
      exit(1);
    }
  }
  close(sock);
  printf("Client %d disconnected\n", cnt);
  free(arg);
 
  return;
}
