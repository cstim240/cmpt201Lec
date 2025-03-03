#define _POSIX_C_SOURCE 200809L
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void *myThreadFunc(void *arg) {
  char *msg = arg;
  printf("Hello world! From a THREAD\n");
  printf("The argument is: %s\n", msg);
  return (void *)strlen(msg);
}

int main() {
  pthread_t id;
  pthread_create(&id, NULL, myThreadFunc, "bazinga");
  printf("In main!\n");
  void *retVal = NULL;
  // sleep(1);
  pthread_join(id, &retVal);
  uint64_t len = (uint64_t)retVal;
  printf("Return value is: %lu\n", len);
}
