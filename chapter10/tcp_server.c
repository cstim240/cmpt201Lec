#include <stdbool.h>
#include <stdio.h>
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
  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, "tmp", sizeof(addr.sun_path) - 1);
  int ret = bind(socket_fd, &addr, sizeof(addr));

  if (ret == -1) {
    perror("bind");
  }

  // 3. LISTEN
  const int BACKLOG_SIZE = 7;
  ret = listen(socket_fd, BACKLOG_SIZE);

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
    // 6. WRITE - nothing for the moment...
    //
    // 7. CLose
    close(connection_fd);
  }
}
