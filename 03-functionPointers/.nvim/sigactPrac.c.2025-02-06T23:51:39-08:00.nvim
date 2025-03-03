#define _POSIX_C_SOURCE 200809
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *msg = "Ctrl-C pressed!\n";
void handle_sigint(int signum) {
  write(STDOUT_FILENO, msg, strlen(msg));
  // printf is not signal safe
  exit(0);
}

int main() {
  // configure struct sigaction act handler
  struct sigaction act;
  act.sa_handler = handle_sigint;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);

  // register signal handler
  int ret = sigaction(SIGINT, &act, NULL);
  if (ret == -1) {
    perror("Sigaction() failed");
    exit(EXIT_FAILURE);
  }

  while (1) {
    sleep(1);
  }
}
