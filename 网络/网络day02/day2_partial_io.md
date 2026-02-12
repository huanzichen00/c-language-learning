# Net Day2：部分读写与消息边界

## 今日唯一知识点
`send/recv` 不是“发多少收多少一次到位”，可能发生部分读写。

## 练习题（30~60 分钟）
目标：在 Day1 基础上实现“长度前缀协议”最小闭环。

- 客户端发送：`[4字节长度][消息体]`
- 服务端接收：先读 4 字节长度，再按长度读完整消息，再回显同样协议

## 你要实现的函数
- `ssize_t send_all(int fd, const void *buf, size_t len)`
- `ssize_t recv_all(int fd, void *buf, size_t len)`

要求：循环调用 `send/recv` 直到完成指定字节数或出错。

## 编译
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/net_day2/echo_server_len.c -o /tmp/echo_server_len
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/net_day2/echo_client_len.c -o /tmp/echo_client_len
```
