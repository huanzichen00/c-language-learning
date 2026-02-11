#include <stdio.h>

int my_strlen(const char *s)
{
    int len = 0;

    // TODO: 遍历到 '\0' 为止，统计长度
    for(int i = 0; s[i] != '\0'; i++) {
        len++;
    }

    return len;
}

int main(void)
{
    char buf[256];

    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        printf("输入无效\n");
        return 1;
    }

    // TODO: 如果 buf 末尾是 '\n'，把它替换成 '\0'
    if (buf[my_strlen(buf) - 1] == '\n') {
        buf[my_strlen(buf) - 1] = '\0';
    }
    // TODO: 输出 len=<长度>
    printf("len=%d\n", my_strlen(buf));

    return 0;
}
