#include <stdio.h>

int is_valid_score(int s)
{
    if (s <= 100 && s >= 0) {
    return 1;
}
return 0;
}

double calc_avg(const int arr[], int n)
{
    // TODO: 计算平均分并返回
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

int main(void)
{
    int n;
    int scores[50];
    int i;

    if (scanf("%d", &n) != 1) {
        printf("输入无效\n");
        return 1;
    }

    if (n < 1 || n > 50) {
        printf("n超范围\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        if (scanf("%d", &scores[i]) != 1) {
            printf("输入无效\n");
            return 1;
        }

        if (!is_valid_score(scores[i])) {
            printf("分数超范围\n");
            return 1;
        }
    }

    // TODO: 统计 max/min/pass，并输出 5 行结果
    int max = scores[0];
    int min = scores[0];
    int pass = 0;
    for (i = 0; i < n; i++) {
        max = max >= scores[i] ? max : scores[i];
        min = min <= scores[i] ? min : scores[i];
        if (scores[i] >= 60) {
            pass++;
        }
    }
    printf("count=%d\n", n);    
    printf("max=%d\n", max);
    printf("min=%d\n", min);
    printf("avg=%.2f\n",calc_avg(scores, n));
    printf("pass=%d\n", pass);
    return 0;
}
