#include <iostream>
#include <stdlib.h>
using namespace std;
struct rect
{
  int l;
  int b;
};
int main()
{
  // rect r = {10, 5};
  // struct rect *p = &r;
  // cout << r.l << endl;
  // cout << r.b << endl;
  // cout << p->l << endl;
  // cout << p->b << endl;

  struct rect *p;
  p = (struct rect *)malloc(sizeof(struct rect));
  p->l = 25;
  p->b = 30;
  cout << p->l << endl;
  cout << p->b << endl;
}