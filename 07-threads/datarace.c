#define _POSIX_C_SOURCE 200809L
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int cnt = 0;

void *myThreadFunc(void *arg) {
  for (int i = 0; i < 1000000; i++) {
    cnt++;
  }
  return NULL;
}

int main() {
  pthread_t id0;
  pthread_t id1;
  pthread_create(&id0, NULL, myThreadFunc, NULL);
  pthread_create(&id1, NULL, myThreadFunc, NULL);
  pthread_join(id0, NULL);
  pthread_join(id1, NULL);
  printf("Answer is %d\n", cnt);
}
