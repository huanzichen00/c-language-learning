#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 200

typedef struct {
    char name[32];
    char phone[32];
    char email[64];
} Contact;

void print_menu(void)
{
    printf("1) add\n");
    printf("2) list\n");
    printf("3) delete\n");
    printf("4) update\n");
    printf("5) find\n");
    printf("6) save\n");
    printf("7) load\n");
    printf("0) quit\n");
    printf("> ");
}

int add_contact(Contact arr[], int *count)
{
    if (*count >= MAX_CONTACTS) {
        printf("通讯录已满\n");
        return 0;
    }

    Contact c;
    if (scanf("%31s %31s %63s", c.name, c.phone, c.email) != 3) {
        printf("输入无效\n");
        return 0;
    }

    arr[*count] = c;
    (*count)++;
    return 1;
}

void list_contacts(const Contact arr[], int count)
{
    for (int i = 0; i < count; i++) {
        printf("%d) %s | %s | %s\n", i, arr[i].name, arr[i].phone, arr[i].email);
    }
}

int main(void)
{
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int cmd;

    while (1) {
        print_menu();
        if (scanf("%d", &cmd) != 1) {
            printf("输入无效\n");
            return 1;
        }

        if (cmd == 0) {
            break;
        } else if (cmd == 1) {
            printf("输入: name phone email\n");
            add_contact(contacts, &count);
        } else if (cmd == 2) {
            list_contacts(contacts, count);
        } else {
            printf("该功能下一步实现\n");
        }
    }

    return 0;
}
