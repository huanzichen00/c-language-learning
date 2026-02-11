#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
    if (scanf("%31s %31s %63s", arr[*count].name, arr[*count].phone, arr[*count].email) == 3) {           
        (*count)++;
        return 1;
    }
    printf("输入无效\n");
    return 0;
}

void list_contacts(const Contact arr[], int count)
{
    // TODO: 遍历并打印所有联系人
    if (count == 0) {
        printf("通讯录为空\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("name:%s ", arr[i].name);
        printf("phone:%s ", arr[i].phone);
        printf("email:%s\n", arr[i].email);
    }
    return;
}

int delete_contact(Contact arr[], int *count)
{
    char name[32];
    if (scanf("%31s", name) != 1) {
        printf("输入无效\n");
        return 0;
    }
    int is_found = 0;
    int index = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(name, arr[i].name) == 0) {
            is_found = 1;
            index = i;
            break;
        }
    }
    if (is_found == 1) {
        for (int i = index; i < *count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*count)--;
        return 1;
    }
    printf("未找到\n");
    return 0;
}

int update_contact(Contact arr[], int count)
{
    char name[32];
    if (scanf("%31s", name) != 1) {
        printf("输入无效\n");
        return 0;
    }
    for (int i = 0; i < count; i++) {
        if (strcmp(name, arr[i].name) == 0) {
            if (scanf("%31s %63s", arr[i].phone, arr[i].email) != 2) {
                printf("输入无效\n"); 
                return 0;
            }
            return 1;
        }
    }
    printf("未找到\n");
    return 0;
}

int find_contact(const Contact arr[], int count)
{
    char name[32];
    if (scanf("%31s", name) != 1) {
        printf("输入无效\n");
        return 0;
    }
    for(int i = 0; i < count; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            printf("name:%s ", arr[i].name);
            printf("phone:%s ", arr[i].phone);
            printf("email:%s\n", arr[i].email);
            return 1;
        }
    }
    printf("未找到\n");
    return 0;
}

int save_contacts(const Contact arr[], int count)
{
    // 1) 读取输出文件名
    char filename[256];
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        printf("输入无效\n");
        return 0;
    }
    filename[strcspn(filename, "\n")] = '\0';
    if (filename[0] == '\0') {
        printf("输入无效\n");
        return 0;
    }
    // 2) fopen("w")
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("无法打开输出文件\n");
        return 0;
    }
    // 3) 逐条 fprintf
    for (int i = 0; i < count; i++) {
        fprintf(fp,"%s ", arr[i].name);
        fprintf(fp,"%s ", arr[i].phone);
        fprintf(fp,"%s\n", arr[i].email);
    }  
    // 4) fclose
    fclose(fp);
    return 1;
}

int load_contacts(Contact arr[], int *count)
{
    char filename[256];
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        printf("输入无效\n");
        return 0;
    }
    filename[strcspn(filename, "\n")] = '\0';
    if (filename[0] == '\0') {
        printf("输入无效\n");
        return 0;
    }
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("无法打开输入文件\n");
        return 0;
    }
    char name[32], phone[32], email[64];
    int scan_ret; 
    *count = 0;
    while (*count < MAX_CONTACTS) {
        scan_ret = fscanf(fp, "%31s %31s %63s", name, phone, email);
        if (scan_ret != 3) {
           break; 
        }           
        strcpy(arr[*count].name , name);
        strcpy(arr[*count].phone , phone);
        strcpy(arr[*count].email , email);        
        (*count)++;
    }
    fclose(fp);
    if (scan_ret == EOF || *count == MAX_CONTACTS) {
        return 1;
    }
    printf("读取失败\n");
    return 0;
}

void clear_stdin_line(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {

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

        clear_stdin_line();

        if (cmd == 0) {
            break;
        } else if (cmd == 1) {
            if (!add_contact(contacts, &count)) {
                printf("add 失败\n");
            }
        } else if (cmd == 2) {
            list_contacts(contacts, count);
        } else if (cmd == 3) {
            if (!delete_contact(contacts, &count)) {
                printf("delete 失败\n");
            }
        } else if (cmd == 4) {
            if (!update_contact(contacts, count)) {
                printf("update 失败\n");
            }
        } else if (cmd == 5) {
            if (!find_contact(contacts, count)) {
                printf("find 失败\n");
            }
        } else if (cmd == 6) {
            if (!save_contacts(contacts, count)) {
                printf("save 失败\n");
            }
        } else if (cmd == 7) {
            if (!load_contacts(contacts, &count)) {
                printf("load 失败\n");
            }
        } else {
            printf("无效命令\n");
        }
    }

    return 0;
}
