#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {

  printf("Server!\n");
  // 1. SOCKET - TCP Server on my local computer
  int socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("Socket");
  }

  // 2. BIND - local socket named "tmp"
  struct sockaddr_un addr;
  memset(&addr, 0, sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, "tmp", sizeof(addr.sun_path) - 1);
  int ret =
      bind(socket_fd, (struct sockaddr_un *)&addr, sizeof(struct sockaddr_un));
  // march 19 update, we cast struct sockaddr*

  if (ret == -1) {
    perror("bind");
  }

  // 3. LISTEN
  const int BACKLOG_SIZE = 7;
  ret = listen(socket_fd, BACKLOG_SIZE);
  if (ret == -1) {
    perror("listen");
  }

  while (true) {
    // 4. ACCEPT
    int connection_fd = accept(socket_fd, NULL, NULL);
    if (connection_fd == -1) {
      perror("accept");
    }
    // 5. READ
    const int SIZE = 1024;
    char buff[SIZE];
    ssize_t bytes_read = read(connection_fd, buff, SIZE);
    // 6. WRITE - nothing for the moment... march 19, added write
    write(STDOUT_FILENO, buff, bytes_read);

    close(connection_fd);
  }

  // 7. close listening socket
  close(socket_fd);
}
