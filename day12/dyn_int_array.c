#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int n;
    int *arr = NULL;
    
    if (scanf("%d", &n) != 1) {
        printf("输入无效\n");
        return 1;
    }

    if (n < 1 || n > 1000) {
        printf("n超范围\n");
        return 1;
    }

    arr = (int *)malloc((size_t)n * sizeof(int));
    if (arr == NULL) {
        printf("内存申请失败\n");
        return 1;
    }
    
    int sum = 0;
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("输入无效\n");
            free(arr);
            return 1;
        }
        max = max > arr[i] ? max : arr[i];
        min = min < arr[i] ? min : arr[i];
        sum += arr[i];
    }
    printf("sum=%d\n", sum);
    printf("max=%d\n", max);
    printf("min=%d\n", min);
    free(arr);
    return 0;
}
