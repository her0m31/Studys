#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread(void *arg);

struct ThreadArgs {
  int sec;
};

int main(int argc, char *argv[]) {
  pthread_t thread_id1, thread_id2;
  struct ThreadArgs *args;

  args = (struct ThreadArgs *)malloc(sizeof(struct ThreadArgs));
  if(args == NULL) {
    fprintf(stderr, "malloc() failure\n");
    exit(1);
  }

  args->sec = 1;
  if(pthread_create(&thread_id1, NULL, (void *)thread, (void *)args) != 0) {
    fprintf(stderr, "pthread_create() failure\n");
    exit(1);
  }

  args = (struct ThreadArgs *)malloc(sizeof(struct ThreadArgs));
  if(args == NULL) {
    fprintf(stderr, "malloc() failure\n");
    exit(1);
  }

  args->sec = 2;
  if(pthread_create(&thread_id2, NULL, (void *)thread, (void *)args) != 0) {
    fprintf(stderr, "pthread_create() failure\n");
    exit(1);
  }

  pthread_join(thread_id1, NULL);
  pthread_join(thread_id2, NULL);

  return 0;
}

void *thread(void *arg) {
  int sec, i;
  
  sec = ((struct ThreadArgs *)arg)->sec;
  for(i = 0; i < 10; i++) {
    sleep(sec);
    printf("Thread %d: %d\n", pthread_self(), i+1);
  }

  free(arg);
  return;
}
