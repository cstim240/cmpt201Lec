#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {

  printf("Server!\n");
  // UDP Server
  // unlike tCP, we won't need listen and accept. We still need to create a
  // socket, bind
  // 1. SOCKET - becomes d_gram
  int socket_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
  if (socket_fd == -1) {
    perror("Socket");
  }

  struct in_addr {
    in_addr_t s_addr;
  };

  struct sockaddr_in {
    sa_family_t AF_INET;
    in_port_t sin_port;
    struct in_addr sin_addr;
    unsigned char __pad[X];
  };

  // 2. BIND - local socket named "tmp"
  struct sockaddr_un addr;
  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, "tmp", sizeof(addr.sun_path) - 1);
  int ret = bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr));
  // march 19 update, we cast struct sockaddr*

  if (ret == -1) {
    perror("bind");
  }

  // 5. READ --> becomes Receive from (recvfrom)
  const int SIZE = 1024;
  char buff[SIZE];
  ssize_t bytes_read = recvfrom(socket_fd, buff, SIZE, 0, NULL, 0);
  // 6. write --> becomes sendto
  write(STDOUT_FILENO, buff, bytes_read);

  close(socket_fd);
}

// 7. close listening socket
