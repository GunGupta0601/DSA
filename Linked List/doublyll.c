#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
  int data;
  struct Node *prev, *next;
} *first = NULL;

void create(int a[], int n)
{
  int i;
  struct Node *t, *last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = a[0];
  first->prev = first->next = NULL;
  last = first;
  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = a[i];
    t->next = last->next;
    t->prev = last;
    last->next = t;
    last = t;
  }
}

void display(struct Node *p)
{
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int length(struct Node *p)
{
  int len = 0;
  while (p != NULL)
  {
    len++;
    p = p->next;
  }
  return len;
}

void insert(struct Node *p, int index, int x)
{
  struct Node *t;
  int i;
  if (index < 0 || index > length(p))
    return;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  if (index == 0)
  {
    t->prev = NULL;
    if (p == first)
    {
      t->next = NULL;
    }
    else
    {
      t->next = first;
      first->prev = t;
      first = t;
    }
  }
  else
  {
    for (i = 0; i < index - 1; i++)
      p = p->next;
    t->prev = p;
    t->next = p->next;
    if (p->next)
      p->next->prev = t;
    p->next = t;
  }
}

int delete(struct Node *p, int index)
{
  struct Node *q;
  int x = -1, i;
  if (index < 1 || index > length(p))
    return -1;
  if (index == 1)
  {
    first = first->next;
    if (first)
      first->prev = NULL;
    x = p->data;
    free(p);
  }
  else
  {
    for (i = 0; i < index - 1; i++)
      p = p->next;
    p->prev->next = p->next;
    if (p->next)
      p->next->prev = p->prev;
    x = p->data;
    free(p);
  }
}

void reverse(struct Node *p)
{
  struct Node *temp;
  while (p != NULL)
  {
    temp = p->next;
    p->next = p->prev;
    p->prev = temp;
    p = p->prev;
    if (p != NULL && p->next == NULL)
      first = p;
  }
}

void main()
{
  int a[5] = {1, 2, 3, 4, 5};
  create(a, 5);
  display(first);
  insert(first, 0, 0);
  display(first);
  delete(first, 0);
  display(first);
  reverse(first);
  display(first);
}
