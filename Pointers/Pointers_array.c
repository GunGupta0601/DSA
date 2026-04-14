#include <stdio.h>
#include <stdlib.h>

int main()
{
  // int a[5] = {1, 2, 3, 4, 5};
  // int *p;
  // p = a;
  // for (int i = 0; i < 5; i++)
  // {
  //   printf("%d\t", a[i]);
  // }
  // printf("\n");
  // for (int i = 0; i < 5; i++)
  // {
  //   printf("%d\t", p[i]);
  // }

  // int *p;
  // p = (int *)malloc(5 * sizeof(int));
  // p[0] = 1;
  // p[1] = 2;
  // p[2] = 3;
  // p[3] = 4;
  // p[4] = 5;
  // for (int i = 0; i < 5; i++)
  // {
  //   printf("%d\t", p[i]);
  // }

  int *p1;
  char *p2;
  float *p3;
  double *p4;
  printf("%d\n", sizeof(p1));
  printf("%d\n", sizeof(p2));
  printf("%d\n", sizeof(p3));
  printf("%d\n", sizeof(p4));
}