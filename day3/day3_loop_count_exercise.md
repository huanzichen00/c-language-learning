# Day3 练习：while 循环的累计统计模式

## 今日唯一知识点
每读到一个输入，就更新一次统计量（计数器）。

## 练习题（10~20 分钟）
文件名：`/root/exercise/day3/num_stats.c`

### 输入
- 多行整数，直到 EOF（Ctrl+D）结束。

### 输出
- `count=<总个数>`
- `sum=<总和>`
- `pos=<正数个数>`
- `neg=<负数个数>`
- `zero=<零的个数>`

### 错误处理
- 如果遇到非整数输入（例如 `abc`）：输出 `输入无效`，返回 `1`。
- 如果是正常 EOF 结束：返回 `0`。

### 边界情况
- 空输入（直接 EOF）也要输出统计结果（都为 0）并正常退出。
- 全是 0、全是负数、混合输入都要正确。

## 编译与运行
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/day3/num_stats.c -o /tmp/num_stats
./tmp/num_stats
```

## 建议测试
```bash
printf "1\n-2\n0\n5\n" | /tmp/num_stats
printf "" | /tmp/num_stats
printf "1\nabc\n" | /tmp/num_stats; echo $?
```
