#define sys / epoll.h
#define LISTEN_BACKLOG 34
#define MAX_EVENTS 10

int main() {
  struct sockaddr_in addr, remote_addr;
  int cfd, epollfd;
  int nfds;
  ssize_t num_read;
  socklen_t addrlen = sizeof(struct sockadd_in);
  char buf[BUF_SIZE];

  sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sfd == -1)
    handle_error("socket");

  memset(&addr, 0, sizeof(struct sockaddr_in));

  // bind
  // listen

  epollfd = epoll_create1(0);
  if (epollfd == -1)
    handle_error("epollfd");
  struct epoll_event ev, events[MAX_EVENTS];
  ev.events = EPOLLIN | EPOLLOUT;
  ev.data.fd = cfd;
  if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sfd, &ev) == -1)
    handle_error("epoll_ctl");
}
