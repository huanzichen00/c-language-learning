#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("用法: %s <ip> <port> <message>", argv[0]);
        return 1;
    }
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return 1;
    }
    struct sockaddr_in addr;
    memset(&addr, 0 , sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons((unsigned short)atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) != 1) {
        perror("inet_pton");
        close(fd);
        return 1;
    }
    if (connect(fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("connect");
        close(fd);
        return 1;
    }  
    size_t len = strlen(argv[3]);
    if (send(fd ,argv[3], len, 0) < 0) {
        perror("send");
        close(fd);
        return 1;
    }
    char buf[1024];
    ssize_t n = recv(fd, buf, sizeof(buf) - 1, 0);
    if (n < 0) {
        perror("recv");
        close(fd);
        return 1;
    }
    if (n == 0) {
        printf("server closed connection\n");
        perror("recv");
        return 1;
    }
    buf[n] = '\0';
    printf("reply: %s\n", buf);
    close(fd);
    return 0;
}
