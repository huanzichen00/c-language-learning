# Day2 练习：if / else if / else 分支覆盖完整性

## 今日唯一知识点
`if / else if / else` 的分支要覆盖所有可能输入，让每种情况都有明确处理。

## 练习题（10~20 分钟）
文件名：`/root/exercise/grade_level.c`

### 输入
- 一个整数分数 `score`（期望范围 0~100）

### 输出规则
- `90~100` 输出 `A`
- `80~89` 输出 `B`
- `70~79` 输出 `C`
- `60~69` 输出 `D`
- `0~59` 输出 `E`

### 错误处理
- 非整数输入：输出 `输入无效`，程序返回 `1`
- 分数超范围（`score < 0` 或 `score > 100`）：输出 `分数超范围`，程序返回 `1`
- 正常输出等级时：程序返回 `0`

## 编译与运行
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/grade_level.c -o /tmp/grade_level
./tmp/grade_level
```

## 建议测试
```bash
printf "95\n" | /tmp/grade_level
printf "82\n" | /tmp/grade_level
printf "70\n" | /tmp/grade_level
printf "59\n" | /tmp/grade_level
printf "-1\n" | /tmp/grade_level
printf "101\n" | /tmp/grade_level
printf "abc\n" | /tmp/grade_level
```

## 提交给我 review 前自检
1. 是否先做了输入合法性检查（`scanf` 返回值）？
2. 是否先做了范围检查（0~100）再做等级判断？
3. 每个分支是否都能明确输出并返回正确退出码？
