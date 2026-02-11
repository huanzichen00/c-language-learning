# Day14 收尾练习：工程习惯（Makefile + gdb + valgrind）

## 今日唯一知识点
把“能跑”升级为“可维护”：可重复构建、可调试、可做内存检查。

## 任务（20~40 分钟）
基于你 Day12 的程序：`/root/exercise/day12/dyn_int_array.c`

### Part A: Makefile
在 `/root/exercise/day14/Makefile` 中实现：
- `all`：生成 `dyn_int_array`
- `run`：喂入一组样例输入并运行
- `clean`：删除二进制与中间文件

要求编译参数：
- `-Wall -Wextra -Werror -std=c11 -g`

### Part B: gdb 最小调试流程
用以下命令实践并记录你看到的关键现象：
```bash
gdb ./dyn_int_array
break main
run
next
print n
quit
```

### Part C: valgrind 内存检查
运行：
```bash
valgrind --leak-check=full --show-leak-kinds=all ./dyn_int_array < <(printf "5 3 8 -2 7 0\n")
```
目标：
- 看到 `definitely lost: 0 bytes`

## 通过标准
- `make` 成功
- `make run` 有正常输出
- `make clean` 清理成功
- 你能口头说明 gdb 每条命令在做什么
- valgrind 无泄漏
