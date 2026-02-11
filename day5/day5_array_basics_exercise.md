# Day5 练习：数组基础（顺序存储 + 遍历）

## 今日唯一知识点
用数组保存一批同类型数据，并通过循环遍历做统计。

## 练习题（10~25 分钟）
文件名：`/root/exercise/day5/array_stats.c`

### 输入
- 第一项是整数 `n`（表示后续有 n 个整数）
- 然后输入 n 个整数

### 输出
- `max=<最大值>`
- `min=<最小值>`
- `sum=<总和>`
- `avg=<平均值，保留2位小数>`

### 约束
- 约定 `1 <= n <= 100`
- 用 `int arr[100]` 存储

### 错误处理
- 输入格式错误（读不到应有的整数）：输出 `输入无效`，返回 `1`
- `n` 超范围：输出 `n超范围`，返回 `1`
- 正常情况返回 `0`

## 编译与运行
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/day5/array_stats.c -o /tmp/array_stats
printf "5 3 8 -2 7 0\n" | /tmp/array_stats
```

## 建议测试
```bash
printf "1 42\n" | /tmp/array_stats
printf "5 3 8 -2 7 0\n" | /tmp/array_stats
printf "0\n" | /tmp/array_stats
printf "3 1 x 2\n" | /tmp/array_stats; echo exit=$?
```
