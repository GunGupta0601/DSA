#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
  int data;
  struct Node *next;
} *head = NULL, *last = NULL;

void create(int a[], int n)
{
  int i;
  struct Node *t, *last;
  head = (struct Node *)malloc(sizeof(struct Node));
  head->data = a[0];
  head->next = head;
  last = head;
  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = a[i];
    t->next = head;
    last->next = t;
    last = t;
  }
}

void display(struct Node *p)
{
  do
  {
    printf("%d ", p->data);
    p = p->next;
  } while (p != head);
  printf("\n");
}

int length(struct Node *p)
{
  int c = 0;
  do
  {
    c++;
    p = p->next;
  } while (p != head);
  return c;
}

void displayRec(struct Node *p)
{
  static int flag = 0;
  if (p != head || flag == 0)
  {
    flag = 1;
    printf("%d ", p->data);
    displayRec(p->next);
  }
  printf("\n");
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
    if (head == NULL)
    {
      head = t;
      head->next = head;
    }
    else
    {
      while (p->next != head)
        p = p->next;
      p->next = t;
      t->next = head;
      head = t;
    }
  }
  else
  {
    for (i = 0; i < index - 1; i++)
      p = p->next;
    t->next = p->next;
    p->next = t;
  }
}

int delete(struct Node *p, int index)
{
  struct Node *q;
  int i, x;
  if (index < 0 || index > length(p))
    return -1;
  if (index == 1)
  {
    while (p->next != head)
      p = p->next;
    x = head->data;
    if (p == head)
    {
      free(head);
      head = NULL;
    }
    else
    {
      p->next = head->next;
      free(head);
      head = p->next;
    }
  }
  else
  {
    for (i = 0; i < index - 2; i++)
      p = p->next;
    q = p->next;
    p->next = q->next;
    x = q->next;
    free(q);
  }
  return x;
}

void main()
{
  int a[5] = {1, 2, 3, 4, 5};
  create(a, 5);
  display(head);
  insert(head, 0, 0);
  display(head);
}
