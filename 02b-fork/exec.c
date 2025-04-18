#include <stdio.h>
#include <unistd.h>

int main() {
  // create a program that creates a child process
  // for the parent: call any one of the exec and execute 'ls -a'
  // for the child call any of the exec functions that executes 'ls -a -l -h'
  pid_t pid = fork();

  if (pid == 0) {
    // child process
    char *args[] = {"ls", "-a", "-l", "-h", NULL};
    execvp("ls", args);
    perror("execvp has failed!\n");
  } else {
    // parent process
    execlp("ls", "ls", "-a", NULL);
    perror("execlp has failed!\n");
  }
}
