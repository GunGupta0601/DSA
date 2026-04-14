#include <stdio.h>
struct Rectangle
{
  int length;
  int breadth;
  char x;
};
int main()
{
  struct Rectangle r1 = {10, 5};
  r1.length = 6;
  r1.breadth = 12;
  printf("%d, %d", r1.length, r1.breadth);
  return 0;
}