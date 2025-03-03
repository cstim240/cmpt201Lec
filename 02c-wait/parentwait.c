#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  // write a program that creates a child process, child process runs 'ls -a
  // -l', parent process waits for the child process to terminate using
  // waitpid(), if child exits normally, print the exit status

  pid_t pid = fork();

  if (pid) { // similar to saying non-zero (or parent) process
    int wstatus = 0;
    if (waitpid(pid, &wstatus, 0) == -1) {
      perror("waitpid failed");
      exit(EXIT_FAILURE);
    }

    if (WIFEXITED(wstatus)) {
      printf("Child done with exit status: %d\n", WEXITSTATUS(wstatus));
    } else {
      printf("Child did not exit normally\n");
    }

  } else {
    // this is the child process
    if (execl("usr/bin/ls", "-a", "-l") == -1) {
      perror("execl");
      exit(EXIT_FAILURE);
    }
  }
}
