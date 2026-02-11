#include <stdio.h>

int adjust_score(int *score, int delta)
{
    // TODO:
    // 1) 先计算调整后的候选值
    // 2) 若不在 0~100，返回 0（且不改原值）
    // 3) 否则写回 *score 并返回 1
    *score += delta;
    if (*score < 0 || *score > 100) {
        *score -= delta;
        return 0;
    }
    return 1;
}

int main(void)
{
    int score;
    int delta;

    if (scanf("%d %d", &score, &delta) != 2) {
        printf("输入无效\n");
        return 1;
    }

    if (adjust_score(&score, delta)) {
        printf("ok score=%d\n", score);
    } else {
        printf("调整失败\n");
    }

    return 0;
}
