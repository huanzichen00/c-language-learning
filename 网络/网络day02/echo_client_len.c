#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

ssize_t recv_all(int fd, void *buf, size_t len)
{
    // TODO
    return -1;
}

ssize_t send_all(int fd, const void *buf, size_t len)
{
    // TODO
    return -1;
}

int main(int argc, char *argv[])
{
    // TODO: 基于 Day1 客户端框架
    // 1) 发送 4 字节网络序长度 + 消息体
    // 2) 接收 4 字节长度 + 回显消息体
    // 3) 打印 reply: ...
    return 0;
}
