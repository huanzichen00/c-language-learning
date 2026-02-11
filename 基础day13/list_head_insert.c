#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void free_list(struct Node *head)
{
    while (head != NULL) {
        struct Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void)
{
    int n;
    struct Node *head = NULL;

    if (scanf("%d", &n) != 1) {
        printf("输入无效\n");
        free_list(head);
        return 1;
    }

    if (n < 1 || n > 100) {
        printf("n超范围\n");
        return 1;
    }

    int i;
    int num;
    for (i = 0; i < n; i++) {
        if (scanf("%d", &num) != 1) {
            printf("输入无效\n");
            free_list(head);
            return 1;
        }
        struct Node *new_node =malloc(sizeof(struct Node));
        if (new_node == NULL) {
            printf("内存申请失败\n");
            free_list(head);
            return 1;
        }
        new_node->value = num;
        new_node->next = head;
        head = new_node;     
    }
    struct Node *node = head;
        while (node != NULL) {
        printf("value=%d\n", node->value);
        node = node->next;
    }
    free_list(head);

    return 0;
}
