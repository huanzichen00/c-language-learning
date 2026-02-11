# Day11 练习：文件读写基础（fopen/fgets/fprintf）

## 今日唯一知识点
用文件流进行输入输出：`fopen` 打开文件，`fgets` 按行读取，`fprintf` 写入结果。

## 练习题（15~30 分钟）
文件：`/root/exercise/day11/line_word_count.c`

### 任务
程序接收两个文件名参数：
- `argv[1]`：输入文件路径
- `argv[2]`：输出文件路径

统计输入文件：
- 行数 `lines`
- 单词数 `words`（以空白字符分隔）

把结果写入输出文件，格式：
- `lines=<数字>`
- `words=<数字>`

### 错误处理
- 参数个数不对：输出 `用法: ./line_word_count <input> <output>`，返回 `1`
- 输入文件打开失败：输出 `无法打开输入文件`，返回 `1`
- 输出文件打开失败：输出 `无法打开输出文件`，返回 `1`

## 编译与运行
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/day11/line_word_count.c -o /tmp/line_word_count
printf "hello world\nC language\n" > /tmp/in.txt
/tmp/line_word_count /tmp/in.txt /tmp/out.txt
cat /tmp/out.txt
```
