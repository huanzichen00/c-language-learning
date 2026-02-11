#include <stdio.h>

int main(void)
{
    int score;

    if (scanf("%d", &score) != 1) {
        printf("输入无效\n");
        return 1;
    }

    if (score < 0 || score > 100) {
        printf("分数超范围\n");
        return 1;
    }

    if (score >= 90) {
        printf("A\n");
    } else if (score >= 80) {
        printf("B\n");
    } else if (score >= 70) {
        printf("C\n");
    } else if (score >= 60) {
        printf("D\n");
    } else {
        printf("E\n");
    }
    return 0;
}
