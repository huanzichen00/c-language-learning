#include <stdio.h>

int main(void)
{
    int x;
    int scan_ret;
    int count = 0;
    int sum = 0;
    int pos = 0;
    int neg = 0;
    int zero = 0;

    while ((scan_ret = scanf("%d", &x)) == 1) {
        // TODO: 每读到一个 x，更新 count/sum/pos/neg/zero
        count++;
        sum += x;        
        if (x > 0) {
            pos++;
        } else if (x < 0) {
            neg++;
        } else {
            zero++;
        }
    }

    if (scan_ret != EOF) {
        printf("输入无效\n");
        return 1;
    }

    printf("count=%d\n", count);
    printf("sum=%d\n", sum);
    printf("pos=%d\n", pos);
    printf("neg=%d\n", neg);
    printf("zero=%d\n", zero);

    return 0;
}
