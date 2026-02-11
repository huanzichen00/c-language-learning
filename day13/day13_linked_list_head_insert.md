# Day13 练习：单链表入门（头插法）

## 今日唯一知识点
用“头插法”把新节点插到链表最前面，理解 `next` 指针连接关系。

## 练习题（15~30 分钟）
文件：`/root/exercise/day13/list_head_insert.c`

### 要求
- 定义链表节点：
  - `value`（整型）
  - `next`（指向下一个节点）
- 输入：第一项 `n`（1~100），后续 n 个整数
- 用头插法创建链表
- 输出链表所有值（每行一个）：`value=<数字>`
- 最后释放全部节点，避免内存泄漏

### 错误处理
- 输入无效：输出 `输入无效`，返回 `1`
- `n` 越界：输出 `n超范围`，返回 `1`
- `malloc` 失败：输出 `内存申请失败`，返回 `1`

## 编译与运行
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/day13/list_head_insert.c -o /tmp/list_head_insert
printf "5 1 2 3 4 5\n" | /tmp/list_head_insert
```

## 提示
- 头插核心两步：
  1. `node->next = head;`
  2. `head = node;`
