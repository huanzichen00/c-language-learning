# Contacts 实现顺序清单

1. 实现 `list_contacts`
- 先让“显示当前数据”可用，便于后续调试。

2. 实现 `add_contact`
- 先处理容量上限，再读入 3 个字段，最后 `count++`。

3. 实现 `find_contact`
- 按 `name` 精确匹配，找到即打印并返回成功。

4. 实现 `delete_contact`
- 找到目标下标后，用“后项前移”覆盖，最后 `count--`。

5. 实现 `update_contact`
- 先按 `name` 定位，再覆盖对应字段。

6. 实现 `save_contacts`
- 先打开文件，再逐条 `fprintf`，最后 `fclose`。

7. 实现 `load_contacts`
- 先清空/重置 `count`，循环读文件填数组，注意不要超过 `MAX_CONTACTS`。

8. 统一错误处理
- 输入失败、文件打开失败、未找到等分支消息统一。

## 每步都编译检查
```bash
gcc -Wall -Wextra -Werror -std=c11 -g /root/exercise/project1_contacts/contacts_template.c -o /tmp/contacts_app
```
