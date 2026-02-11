# Day6 练习：字符串基础（遍历与长度）

## 今日唯一知识点
字符串是以 `\0` 结尾的字符数组，长度统计本质是遍历到 `\0` 为止。

## 练习题（10~25 分钟）
文件名：`/root/exercise/day6/my_strlen.c`

### 要求
实现函数：
- `int my_strlen(const char *s)`

功能：
- 返回字符串长度（不包含结尾的 `\0`）

### main 行为
- 使用 `fgets` 读取一行到缓冲区（例如 `char buf[256]`）
- 如果读取失败：输出 `输入无效`，返回 `1`
- 如果最后有换行符 `\n`，先去掉
- 调用 `my_strlen` 并输出：`len=<长度>`

### 错误处理
- 读取失败返回 `1`
- 正常返回 `0`

## 编译与运行
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/day6/my_strlen.c -o /tmp/my_strlen
printf "hello\n" | /tmp/my_strlen
```

## 建议测试
```bash
printf "hello\n" | /tmp/my_strlen
printf "\n" | /tmp/my_strlen
printf "abc def\n" | /tmp/my_strlen
```
