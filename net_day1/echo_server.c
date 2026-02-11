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
    // TODO: socket()
    // TODO: 组装 sockaddr_in + inet_pton
    // TODO: bind()
    // TODO: listen()
    // TODO: accept() 一个客户端
    // TODO: recv() 一次并打印 received: ...
    // TODO: send() 回显
    // TODO: close(client_fd), close(listen_fd)
    return 0;
}
