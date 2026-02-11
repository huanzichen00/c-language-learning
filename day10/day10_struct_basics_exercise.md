# Day10 练习：结构体基础（把相关数据打包）

## 今日唯一知识点
`struct` 用来把多个相关字段组合成一个整体数据类型。

## 练习题（15~30 分钟）
文件：`/root/exercise/day10/student_struct_stats.c`

### 数据结构
定义：
- `struct Student { char name[32]; int score; };`

### 输入
- 第一项 `n`（1~20）
- 接着输入 n 行：`name score`
  - `name` 视为不含空格的单词
  - `score` 范围 `0~100`

### 输出
- `count=<n>`
- `top_name=<最高分学生姓名>`
- `top_score=<最高分>`
- `avg=<平均分, 保留2位>`

### 错误处理
- 输入格式错误：`输入无效`，返回 `1`
- `n` 越界：`n超范围`，返回 `1`
- 任一分数越界：`分数超范围`，返回 `1`

### 要求
- 使用 `struct Student arr[20]` 保存数据
- 至少写一个函数：`double calc_avg(const struct Student arr[], int n)`

## 编译与运行
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/day10/student_struct_stats.c -o /tmp/student_struct_stats
printf "3\nTom 88\nAmy 95\nBob 76\n" | /tmp/student_struct_stats
```
