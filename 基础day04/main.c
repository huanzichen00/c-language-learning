#include <stdio.h>
#include "calc.h"

int main(void)
{
    int a;
    int b;

    if (scanf("%d %d", &a, &b) != 2) {
        printf("输入无效\n");
        return 1;
    }

    printf("add=%d\n", add(a, b));
    printf("sub=%d\n", sub(a, b));
    printf("mul=%d\n", mul(a, b));
    printf("even=%d\n", is_even(a));

    return 0;
}
