#include <stdio.h>

double c_to_f(double c)
{
  double f;
  f = c * 9 / 5 + 32;
  return f;
}
int main(void)
{
  double c;
  int scan_ret;
  while ((scan_ret = scanf("%lf", &c)) == 1)
  {
    printf("C=%.2f -> F=%.2f\n", c, c_to_f(c));
  }
  if (scan_ret != EOF) {
    return 0;
  }
  printf("输入无效\n");
  return 1;
}
