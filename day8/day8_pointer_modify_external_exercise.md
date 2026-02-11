# Day8 练习：用指针在函数内修改外部变量

## 今日唯一知识点
函数参数默认是值传递；想在函数内改到外部变量，必须传地址（指针）。

## 练习题（10~20 分钟）
文件：`/root/exercise/day8/adjust_score.c`

### 需求
实现函数：
- `int adjust_score(int *score, int delta)`

规则：
- 把 `*score` 加上 `delta`
- 调整后分数必须仍在 `0~100`
- 如果越界，不修改原值并返回 `0`
- 如果成功修改，返回 `1`

### main 行为
- 输入两个整数：`score delta`
- 输入无效：输出 `输入无效`，返回 `1`
- 调用 `adjust_score`
- 成功：输出 `ok score=<新分数>`
- 失败：输出 `调整失败`
- 正常返回 `0`

## 编译与运行
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/day8/adjust_score.c -o /tmp/adjust_score
printf "60 5\n" | /tmp/adjust_score
```

## 建议测试
```bash
printf "60 5\n" | /tmp/adjust_score
printf "0 -1\n" | /tmp/adjust_score
printf "95 10\n" | /tmp/adjust_score
printf "abc 3\n" | /tmp/adjust_score; echo exit=$?
```
