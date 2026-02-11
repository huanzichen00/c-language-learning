#include <stdio.h>

struct Student {
    char name[32];
    int score;
};

double calc_avg(const struct Student arr[], int n)
{
    // TODO: 计算平均分
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i].score;
    }
    return (double) sum / n;
}

int main(void)
{
    int n;
    struct Student arr[20];
    int i;

    if (scanf("%d", &n) != 1) {
        printf("输入无效\n");
        return 1;
    }

    if (n < 1 || n > 20) {
        printf("n超范围\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        if (scanf("%31s %d", arr[i].name, &arr[i].score) != 2) {
            printf("输入无效\n");
            return 1;
        }

        if (arr[i].score < 0 || arr[i].score > 100) {
            printf("分数超范围\n");
            return 1;
        }
    }

    // TODO: 找最高分学生并输出 count/top_name/top_score/avg
    int index = 0;
    for (i = 0; i < n; i++) {
        index = arr[index].score > arr[i].score ? index : i;
    }
    printf("count=%d\n", n);
    printf("top_name=%s\n", arr[index].name);
    printf("top_score=%d\n", arr[index].score);
    printf("avg=%.2f\n", calc_avg(arr, n));
    return 0;
}
