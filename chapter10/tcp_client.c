#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define MY_SOCK_PATH "tmp"
#define BUF_SIZE 64
@
#define handle_error(msg)                                                      \
  do {                                                                         \
    perror(msg);                                                               \
    exit(EXIT_FAILURE);                                                        \
  } while (0) // use :b# to switch between 'buffers'

    int
    main() {
  printf("Client\n");
  // 1. SCOKET
  int client_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (client_fd == -1) {
    handle_error("socket");
  }
  // 3. CONNECT
  struct sockaddr_un addr;
  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, "tmp", sizeof(addr.sun_path));
  int res = connect(client_fd, &addr, sizeof(addr));
  if (res == -1) {
    handle_error("connect");
  }
  // 4. WRITE
  int bytes_written = write(client_fd, "Hello world", strlen("Hello world"));
  // 5. READ - skip?
  // 6. CLOSE
  close(client_fd);
}
