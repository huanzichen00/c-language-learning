# Day9 练习：用指针遍历数组

## 今日唯一知识点
数组名在很多表达式中会退化为首元素地址，可用指针遍历整个数组。

## 练习题（10~25 分钟）
文件：`/root/exercise/day9/array_stats_ptr.c`

### 输入
- 第一项 `n`（1~100）
- 后续 n 个整数

### 输出
- `max=<最大值>`
- `min=<最小值>`
- `sum=<总和>`
- `avg=<平均值,保留2位>`

### 要求（重点）
- 必须使用指针遍历，不用 `arr[i]` 形式做主循环统计
- 可用变量：
  - `int *p = arr;`
  - `int *end = arr + n;`
- 用 `while (p < end)` 遍历

### 错误处理
- 输入无效：`输入无效`，返回 `1`
- n 越界：`n超范围`，返回 `1`

## 编译与运行
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/day9/array_stats_ptr.c -o /tmp/array_stats_ptr
printf "5 3 8 -2 7 0\n" | /tmp/array_stats_ptr
```
