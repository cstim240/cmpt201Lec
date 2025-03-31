#define _POSIX_C_SOURCE 200809L
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {
  printf("Client (UDP)!\n");
  int socket_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
  if (socket_fd == -1) {
    perror("socket");
  }

  // 2. create sockaddr struct for later sendto
  struct sockaddr_un addr;
  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, "tmp", sizeof(addr.sun_path) - 1);

  printf("Password is: 12345\n");

  // 3. sendto
  const int SIZE = 1024;
  char buff[SIZE];
  snprintf(buff, SIZE, "Hello world from UDP land!\n");
  ssize_t bytes_sent = sendto(socket_fd, buff, strnlen(buff, SIZE), 0,
                              (struct sockaddr *)&addr, sizeof(addr));

  close(socket_fd);
}
