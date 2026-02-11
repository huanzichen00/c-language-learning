# Day7 阶段复盘小项目：student_stats.c

## 今日唯一知识点
把前 6 天基础拼成一个完整小程序（输入校验 + 函数拆分 + 数组统计）。

## 任务（20~30 分钟）
文件：`/root/exercise/day7/student_stats.c`

### 输入
- 第一项：`n`（学生人数，1~50）
- 接着输入 n 个整数分数（0~100）

### 输出
- `count=<n>`
- `max=<最大分>`
- `min=<最小分>`
- `avg=<平均分, 保留2位>`
- `pass=<及格人数(>=60)>`

### 错误处理
- 读不到整数：输出 `输入无效`，返回 `1`
- `n` 不在 1~50：输出 `n超范围`，返回 `1`
- 任一分数不在 0~100：输出 `分数超范围`，返回 `1`

### 结构要求（重点）
- 至少拆 2 个函数：
  - `int is_valid_score(int s)`
  - `double calc_avg(const int arr[], int n)`
- `main` 负责流程和 I/O，不要把所有逻辑塞在 `main`。

## 编译与运行
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/day7/student_stats.c -o /tmp/student_stats
printf "5 66 80 59 100 0\n" | /tmp/student_stats
```

## 建议测试
```bash
printf "5 66 80 59 100 0\n" | /tmp/student_stats
printf "1 60\n" | /tmp/student_stats
printf "0\n" | /tmp/student_stats
printf "3 90 101 70\n" | /tmp/student_stats
printf "3 90 x 70\n" | /tmp/student_stats; echo exit=$?
```
