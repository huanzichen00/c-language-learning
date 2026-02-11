#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // 用法: ./echo_client <ip> <port> <message>
    // TODO: 参数检查
    // TODO: socket()
    // TODO: connect()
    // TODO: send(argv[3])
    // TODO: recv() 回复并打印 reply: ...
    // TODO: close(fd)
    return 0;
}
