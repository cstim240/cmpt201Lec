#include <stdio.h>
#include <unistd.h>
int main() {
  int ogParent = getpid();
  printf("Start PID=%d, parent PID=%d\n", ogParent, getppid());
  fork();
  int childPID = getppid();
  if (getpid() == ogParent) {
    printf("PARENT: PID=%d, child PID=%d\n", getpid(), childPID);
  } else {
    printf("CHILD: PID=%d, parent PID=%d\n", getpid(), getppid());
  }
  return 0;
}
