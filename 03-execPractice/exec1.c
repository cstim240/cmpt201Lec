#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    printf("Child: PID=%d, parent PID= %d\n", getpid(), getppid());
    execlp("ls", "ls", "-a", "-l", "-h", NULL);
  } else {
    printf("PARENT: PID %d, child PID:%d\n", getpid(), pid);
    execlp("ls", "ls", "-a", NULL);
  }
}
