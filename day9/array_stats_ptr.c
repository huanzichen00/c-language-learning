#include <stdio.h>

int main(void)
{
    int n;
    int arr[100];
    int i;

    if (scanf("%d", &n) != 1) {
        printf("输入无效\n");
        return 1;
    }

    if (n < 1 || n > 100) {
        printf("n超范围\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("输入无效\n");
            return 1;
        }
    }

    int *p = arr;
    int *end = arr + n;

    int max = p[0];
    int min = p[0];
    int sum = 0;
    while (p < end) {
        max = max >= *p ? max : *p;
        min = min <= *p ? min : *p;
        sum += *p;
        p++;
    }
    printf("max=%d\n", max);
    printf("min=%d\n", min);
    printf("sum=%d\n", sum);
    printf("avg=%.2f\n", (double)sum / n);
    return 0;
}
