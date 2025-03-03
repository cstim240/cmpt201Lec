#define _POSIX_C_SOURCE 200809
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *message = "ctrl-c pressed!\n";
void handle_sigaction(int num) {
  write(STDOUT_FILENO, message, strlen(message));
  // exit(0);
}

int main() {
  // write a program that creates two processes:
  // parent process should: use sigaction() and have a SIGINT handler, print
  // "ctrl-C is pressed" infinite loop calling sleep() child process should:
  // infinite loop that periodically sends SIGINT to the parent and sleeps

  pid_t pid = fork();
  if (pid) {
    // handle parent process
    struct sigaction sigact;
    sigact.sa_handler = handle_sigaction;
    sigact.sa_flags = 0;
    sigemptyset(&sigact.sa_mask);

    // registers sigaction
    int res = sigaction(SIGINT, &sigact, NULL);
    if (res == -1) {
      perror("sigaction error");
      exit(EXIT_FAILURE);
    }

    while (1) {
      sleep(1);
    }

  } else {
    // handle child process
    // infinite loop that periodically sends SIGINT to the parent and sleeps
    while (1) {
      sleep(1);
      kill(getppid(), SIGINT);
    }
  }
}
