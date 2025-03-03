#include <stdio.h>
#include <unistd.h>

int main() {
  while (1) {
    fork();
    printf("Just forked!\n");
    // sleep(2);
  }
}
