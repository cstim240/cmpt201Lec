#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main() {
  printf("Will sleep in a bit\n");
  char *message = "Hello world!\n";
  for (int i = 0; i < strlen(message); i++) {
    printf("%c", message[i]);
    fflush(stdout);
    sleep(1);
  }
}
