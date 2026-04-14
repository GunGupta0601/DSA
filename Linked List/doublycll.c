#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
  int data;
  struct Node *prev, *next;
} *first = NULL;

void display(struct Node *p)
{
  do
  {
    printf("%d ", p->data);
    p = p->next;
  } while (p != first);
  printf("\n");
}
