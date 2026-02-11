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

    // TODO: 计算 max / min / sum / avg 并按要求输出
    int max = arr[0];
    int min = arr[0];
    int sum = 0;
    for (i = 0; i < n;  i++) {
        sum += arr[i];
        max = max >= arr[i] ? max : arr[i];
        min = min <= arr[i] ? min : arr[i];
    }
    double avg = (double)sum / n;
    printf("max=%d\n", max);
    printf("min=%d\n", min);
    printf("sum=%d\n", sum);
    printf("avg=%.2f\n", avg);
    return 0;
}
