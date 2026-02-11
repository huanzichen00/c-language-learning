2 周学习路线（每天 30~60 分钟）

- Day1：编译-运行闭环 + `main`/函数调用  
  练习：温度转换器（循环读入，函数转换，直到 EOF）
- Day2：变量、类型、`if/else`  
  练习：闰年判断 + 非法输入处理
- Day3：`for/while` 与计数逻辑  
  练习：统计输入中的数字/字母/空白字符
- Day4：函数声明、定义、返回值  
  练习：`calc.h` + `calc.c` + `main.c` 拆分
- Day5：数组基础  
  练习：读入 n 个数，求 max/min/avg
- Day6：字符串基础与 `<string.h>`  
  练习：手写 `my_strlen`、`my_strcmp`
- Day7：周复盘 + 小项目1  
  练习：成绩统计器（数组+函数）
- Day8：指针基础（地址/解引用）  
  练习：交换两个变量、函数内修改外部值
- Day9：指针与数组关系  
  练习：用指针重写 Day5 核心逻辑
- Day10：结构体  
  练习：`Student` 数组，按分数找最高
- Day11：文件读写（`fopen/fgets/fprintf`）  
  练习：统计文本行数与单词数
- Day12：动态内存（`malloc/free`）  
  练习：动态分配字符串数组并释放
- Day13：简单数据结构（单链表）  
  练习：插入、遍历、释放
- Day14：工程习惯日（Makefile/gdb/valgrind/风格）  
  练习：把 Day11 或 Day12 工程化并调试一轮

Day1（讲解 <= 15 行）

- 今天只学 1 个点：`从源码到可执行程序的最小闭环`。  
- 你写 `temp_conv.c`，入口是 `main`。  
- 把“计算逻辑”放进函数，`main` 只做输入/输出流程。  
- 输入一行一个摄氏温度，循环读取直到 EOF。  
- 每读到一个值，就调用函数转换并输出。  
- 编译时开警告并当错误处理，尽早修习惯。  
- 保留 `-g`，后面出 bug 能直接用 `gdb` 定位源码行。  

练习题（10~30 分钟）

题目：`temp_conv.c`（函数版温度转换器）

- 输入：多行浮点数（每行一个摄氏温度），直到 EOF。  
- 输出：每行 `C=xx.xx -> F=yy.yy`（保留 2 位小数）。  
- 必做结构：  
  - 写 `double c_to_f(double c)`，只做转换。  
  - `main` 中循环读入并调用该函数输出。  
- 边界情况：  
  - 空输入时程序正常退出。  
  - 负数、0、大数（如 1000）正常处理。  
  - 出现非法输入（如字母）时打印错误并返回非 0。  

运行/调试命令

```bash
# 编译
gcc -Wall -Wextra -Werror -std=c11 -g temp_conv.c -o temp_conv
```

- `-Wall`：开启常用警告  
- `-Wextra`：开启额外警告  
- `-Werror`：警告当错误  
- `-std=c11`：使用 C11 标准  
- `-g`：生成调试符号（给 gdb 用）  
- `-o temp_conv`：指定输出文件名

```bash
# 运行（Ctrl+D 结束输入）
./temp_conv

# 管道输入测试
printf "0\n100\n-40\n" | ./temp_conv

# gdb 调试
gdb ./temp_conv

# valgrind（Day8+ 会更常用）
valgrind --leak-check=full --show-leak-kinds=all ./temp_conv
```

先回答我 2 个确认问题，再进入你写代码阶段：  
1. `-g` 和 `-Wall/-Wextra` 的作用区别是什么？  
2. 你准备用什么条件区分“EOF”和“非法输入”？
