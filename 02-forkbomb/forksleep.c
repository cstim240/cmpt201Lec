#include <stdio.h>
#include <unistd.h>

int main() {
  // int ret_val = fork();
  for (int i = 0; i < 20; i++) {
    fork();

    // printf("Sleeping %d\n", ret_val);
    printf("Sleeping");
    sleep(5);
  }
  printf("Done!\n");
}
