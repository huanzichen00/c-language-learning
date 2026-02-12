#include <stdio.h>

int is_adult(int age) {
  if (age >= 18) {
    return 1;
  }
  return 0;
}

int main(void) {
  int age;

  printf("请输入年龄: ");
  if (scanf("%d", &age) != 1) {
    printf("输入无效\n");
    return 1;
  }

  if (age < 0) {
    printf("年龄不能为负数\n");
    return 1;
  }

  if (is_adult(age)) {
    printf("你已成年\n");
  } else {
    printf("你未成年\n");
  }

  return 0;
}
