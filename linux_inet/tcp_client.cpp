#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htonl(8080);
    inet_pton(AF_INET, "10.144.144.117", &addr.sin_addr);
    int ret = connect(sock_fd, (struct sockaddr *)(&addr), sizeof(addr));
    char buf[1024] = {0};
    while (1)
    {
        int n = read(STDIN_FILENO, buf, sizeof(buf));
        write(sock_fd, buf, n);
        int n_recv = read(sock_fd, buf, sizeof(buf));
        printf("recv data: %s", buf);
    }
    close(sock_fd);
    return 0;
}