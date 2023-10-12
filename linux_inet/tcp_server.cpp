#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main()
{
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htonl(8080);
    int ret = inet_pton(AF_INET, "10.144.144.17", &sock_addr.sin_addr);
    ret = bind(sock_fd, (struct sockaddr *)(&sock_addr), sizeof(sock_addr));
    if (ret < -1)
    {
        perror("bind sock failed");
    }
    ret = listen(sock_fd, 128);
    if (ret < -1)
    {
        perror("listen failed");
    }
    int lis_fd = accept(sock_fd, NULL, NULL);
    while (1)
    {
    }
    return 0;
}