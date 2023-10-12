#include <iostream>

#include <sys/errno.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#include "threadpool.hpp"

struct Reactor
{
    int fd;
    int ev;
    std::function<void()> callback;
};

class EpollReactors
{
    int epfd;

    EpollReactors()
    {
        epfd = epoll_create(1024);
    }

public:
    template <class F, class... Args>
    void addEvent(int fd, int event, Reactor *reactor, F &&f, Args &&...args)
    {
        reactor->fd = fd;
        reactor->ev = event;
        reactor->callback = std::bind(std::forward<F>(f), std::forward<Args>(args)...);

        epoll_event ev;
        ev.events = event;
        ev.data.ptr = reactor;
        epoll_ctl(epfd, event, fd, &ev);
    }
};

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Please Input ip addr and port!" << std::endl;
        exit(0);
    }
    int port = atoi(argv[2]);
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in srv_addr;
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &(srv_addr.sin_addr));

    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    int ret = bind(lfd, reinterpret_cast<sockaddr *>(&srv_addr), sizeof(srv_addr));
    if (ret < -1)
    {
        std::cout << "bind failed!" << std::endl;
    }
    ret = listen(lfd, 128);

    int epfd = epoll_create(100);

    return 0;
}
