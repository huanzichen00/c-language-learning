# Day4 练习：函数声明与定义分离

## 今日唯一知识点
把“声明(.h)”和“定义(.c)”分开，让主程序只依赖接口。

## 练习题（10~25 分钟）
你需要完成 3 个文件：
- `/root/exercise/day4/calc.h`
- `/root/exercise/day4/calc.c`
- `/root/exercise/day4/main.c`

### 功能要求
实现 4 个函数：
- `int add(int a, int b)`
- `int sub(int a, int b)`
- `int mul(int a, int b)`
- `int is_even(int x)`（偶数返回 1，否则返回 0）

### 文件要求
- `calc.h`：只放函数声明（接口）
- `calc.c`：放函数定义（实现）
- `main.c`：读取两个整数，调用前三个函数输出；再输出第一个数是否偶数

### 输入输出
输入：两个整数 `a b`
输出格式（每行一个）：
- `add=<结果>`
- `sub=<结果>`
- `mul=<结果>`
- `even=<0或1>`

### 错误处理
- 输入不是两个整数：输出 `输入无效`，返回 `1`
- 正常情况返回 `0`

## 编译与运行
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/day4/main.c /root/exercise/day4/calc.c -o /tmp/calc_app
printf "7 3\n" | /tmp/calc_app
printf "abc 3\n" | /tmp/calc_app; echo exit=$?
```
