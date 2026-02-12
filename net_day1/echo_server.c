#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // 用法: ./echo_server <ip> <port>
    // TODO: 参数检查
    if (argc != 3) {
        printf("用法: %s <ip> <port>\n", argv[0]);
        return 1;
    }
    // TODO: socket()
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket");
        return 1;
    }
    // TODO: 组装 sockaddr_in + inet_pton
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons((unsigned short)atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) != 1) {
        perror("inet_pton");
        close(listen_fd);
        return 1;
    }
    if (bind(listen_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(listen_fd);
        return 1;
    }
    // TODO: bind()
    // TODO: listen()
    if (listen(listen_fd, 5) < 0) {
        perror("listen");
        close(listen_fd);
        return 1;
    }
    // TODO: accept() 一个客户端
    int client_fd = accept(listen_fd, NULL, NULL);
    if (client_fd < 0) {
        perror("accept");
        close(listen_fd);
        return 1;
    }
    // TODO: recv() 一次并打印 received: ...
    char buf[1024];
    ssize_t n = recv(client_fd, buf, sizeof(buf) - 1, 0);
    if (n < 0) {
        perror("recv");
        close(client_fd);
        close(listen_fd);
        return 1;
    }    
    if (n == 0) {
        printf("client closed connection\n");
        close(client_fd);
        close(listen_fd);
    }
    buf[n] = '\0';
    printf("received: %s\n", buf);

    // TODO: send() 回显
    if (send(client_fd, buf, (size_t)n, 0) <0 ) {
        perror("send");
        close(client_fd);
        close(listen_fd);
        return 1;
    }

    // TODO: close(client_fd), close(listen_fd)
    close(client_fd);
    close(listen_fd);
    return 0;
}
