# Day12 练习：动态内存基础（malloc/free）

## 今日唯一知识点
当数据规模运行时才知道时，用 `malloc` 动态申请内存，并在结束前 `free` 释放。

## 练习题（15~30 分钟）
文件：`/root/exercise/day12/dyn_int_array.c`

### 输入
- 第一项 `n`（1~1000)
- 后续 n 个整数

### 功能
- 用 `malloc` 动态申请 `n` 个 `int`
- 读入并统计：`sum`、`max`、`min`
- 输出：
  - `sum=<值>`
  - `max=<值>`
  - `min=<值>`

### 错误处理
- 输入无效：`输入无效`，返回 `1`
- `n` 越界：`n超范围`，返回 `1`
- `malloc` 失败：`内存申请失败`，返回 `1`

### 要求
- 正常/异常路径都要避免内存泄漏
- 程序结束前必须 `free`

## 编译与检查
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/day12/dyn_int_array.c -o /tmp/dyn_int_array
printf "5 3 8 -2 7 0\n" | /tmp/dyn_int_array
valgrind --leak-check=full --show-leak-kinds=all /tmp/dyn_int_array < <(printf "5 3 8 -2 7 0\n")
```
