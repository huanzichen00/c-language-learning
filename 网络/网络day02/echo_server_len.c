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
    // TODO: 循环 recv，直到收满 len 字节
    return -1;
}

ssize_t send_all(int fd, const void *buf, size_t len)
{
    // TODO: 循环 send，直到发满 len 字节
    return -1;
}

int main(int argc, char *argv[])
{
    // TODO: 基于 Day1 服务端框架
    // 1) 接收 4 字节网络序长度 (uint32_t)
    // 2) 转主机序，分配缓冲区
    // 3) recv_all 收消息体
    // 4) 回显同样协议: 先发长度，再发消息体
    return 0;
}
