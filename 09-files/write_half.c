#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  // open file (create, read/write permission)
  int fd = open("tmp", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  printf("My file descriptor is %d\n", fd);
  printf("STD out: %d\n", STDOUT_FILENO);
  // write data
  char *msg = "Hello, hope this works well!\n";
  int res = write(fd, msg, strlen(msg));

  // seek middle of file
  int half = -1 * strlen(msg) / 2;
  lseek(fd, half, SEEK_END);
  // read data
  const int MAX_SIZE = 1024;
  char buff[MAX_SIZE];
  int size = read(fd, buff, MAX_SIZE);
  write(STDOUT_FILENO, buff, size);
  // close file
  res = close(fd);
}
