# Net Day1：socket 最小闭环（本地自测）

## 今日唯一知识点
先打通 TCP 最小链路：服务端 accept 后读一条消息并回发，客户端发送并接收。

## 目标（30~60 分钟）
- 完成 `echo_server.c`
- 完成 `echo_client.c`
- 在 localhost 跑通一次回显

## 约束
- 只处理一个客户端连接（今天不做并发）
- 文本消息长度限制 1024
- 发生系统调用错误时要 `perror` 并退出

## 编译
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/net_day1/echo_server.c -o /tmp/echo_server
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/net_day1/echo_client.c -o /tmp/echo_client
```

## 运行
```bash
# 终端1
/tmp/echo_server 127.0.0.1 9090

# 终端2
/tmp/echo_client 127.0.0.1 9090 "hello"
```

## 预期
- 客户端打印：`reply: hello`
- 服务端打印：`received: hello`

## 自检问题
1. 为什么服务端要先 `bind` 再 `listen`？
2. 为什么 `send/recv` 的返回值必须检查？
