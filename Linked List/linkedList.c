#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
  int data;
  struct Node *next;
} *first = NULL, *second = NULL, *last = NULL;

void create(int a[], int n)
{
  int i;
  struct Node *t, *last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = a[0];
  first->next = NULL;
  last = first;
  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = a[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

void create2(int a[], int n)
{
  int i;
  struct Node *t, *last;
  second = (struct Node *)malloc(sizeof(struct Node));
  second->data = a[0];
  second->next = NULL;
  last = second;
  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = a[i];
    t->next = NULL;
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

void displayRec(struct Node *p)
{
  if (p != NULL)
  {
    printf("%d ", p->data);
    displayRec(p->next);
  }
  printf("\n");
}

void displayRecRev(struct Node *p)
{
  if (p != NULL)
  {
    displayRecRev(p->next);
    printf("%d ", p->data);
  }
  printf("\n");
}

int count(struct Node *p)
{
  int c = 0;
  while (p != NULL)
  {
    c++;
    p = p->next;
  }
  return c;
}

int countRec(struct Node *p)
{
  int c = 0;
  if (p == NULL)
    return 0;
  else
    return countRec(p->next);
}

int sum(struct Node *p)
{
  int sum = 0;
  while (p != NULL)
  {
    sum += p->data;
    p = p->next;
  }
  return sum;
}

int sumRec(struct Node *p)
{
  if (p == NULL)
    return 0;
  else
    return sumRec(p->next) + p->data;
}

int max(struct Node *p)
{
  int max = -32768;
  while (p)
  {
    if (p->data > max)
    {
      max = p->data;
    }
    p = p->next;
  }
  return max;
}

int maxRec(struct Node *p)
{
  int x = 0;
  if (p)
    return 0;
  x = maxRec(p->next);
  return x > p->data ? x : p->data;
}

struct Node *search(struct Node *p, int key)
{
  while (p)
  {
    if (key == p->data)
      return p;
    p = p->next;
  }
  return NULL;
}

struct Node *searchRec(struct Node *p, int key)
{
  if (!p)
    return NULL;
  if (key == p->data)
    return p;
  return searchRec(p->next, key);
}

struct Node *searchImp(struct Node *p, int key)
{
  struct Node *q = NULL;
  while (p)
  {
    if (key == p->data)
    {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;
}

void insert(struct Node *p, int index, int x)
{
  struct Node *t;
  if (index < 0 || index > count(p))
    return;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  if (index == 0)
  {
    t->next = first;
    first = t;
  }
  else
  {
    for (int i = 0; i < index - 1; i++)
      p = p->next;
    t->next = p->next;
    p->next = t;
  }
}

void insertLast(struct Node *p, int x)
{
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;
  if (first == NULL)
  {
    first = last;
    first = t;
  }
  else
  {
    last->next = t;
    last = t;
  }
}

void insertSorted(struct Node *p, int x)
{
  struct Node *t, *q = NULL;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;
  if (first == NULL)
    first = t;
  else
  {
    while (p && p->data < x)
    {
      q = p;
      p = p->next;
    }
    if (p == first)
    {
      t->next = first;
      first = t;
    }
    else
    {
      t->next = q->next;
      q->next = t;
    }
  }
}

int delete(struct Node *p, int index)
{
  struct Node *q = NULL;
  int x = -1;
  if (index < 1 || index > count(p))
    return 0;
  if (index == 1)
  {
    q = first;
    x = first->data;
    first = first->next;
    free(q);
    return x;
  }
  else
  {
    for (int i = 0; i < index - 1; i++)
    {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;
  }
}

int isSorted(struct Node *p)
{
  int x = -65536;
  while (p)
  {
    if (p->data < x)
      return 0;
    x = p->data;
    p = p->next;
  }
  return 1;
}

void removeDuplicate(struct Node *p)
{
  struct Node *q = p->next;
  while (q)
  {
    if (p->data != q->data)
    {
      p = q;
      q = q->next;
    }
    else
    {
      p->next = q->next;
      free(q);
      q = p->next;
    }
  }
}

void reverse1(struct Node *p)
{
  int *a, i = 0;
  struct Node *q;
  a = (int *)malloc(count(p) * sizeof(int));
  while (q)
  {
    a[i] = q->data;
    q = q->next;
    i++;
  }
  q = p;
  i--;
  while (q)
  {
    q->data = a[i];
    q = q->next;
    i--;
  }
}

void reverse2(struct Node *p)
{
  struct Node *q = NULL, *r = NULL;
  while (p)
  {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  first = q;
}

void reverse3(struct Node *q, struct Node *p)
{
  if (p)
  {
    reverse3(p, p->next);
    p->next = q;
  }
  else
  {
    first = q;
  }
}

void concatinate(struct Node *p, struct Node *q)
{
  while (p->next != NULL)
  {
    p = p->next;
  }
  p->next = second;
  second = NULL;
}

void merge(struct Node *p, struct Node *q)
{
  struct Node *third = NULL, *last = NULL;
  if (p->data < q->data)
  {
    third = last = first;
    p = p->next;
    last->next = NULL;
  }
  else
  {
    third = last = second;
    q = q->next;
    last->next = NULL;
  }
  while (p != NULL && q != NULL)
  {
    if (p->data < q->data)
    {
      last->next = p;
      last = p;
      p = p->next;
      last->next = NULL;
    }
    else
    {
      last->next = q;
      last = q;
      q = q->next;
      last->next = NULL;
    }
  }
  if (p != NULL)
  {
    last->next = p;
  }
  else
  {
    last->next = q;
  }
}

int isLoop(struct Node *f)
{
  struct Node *p, *q;
  p = q = f;
  do
  {
    p = p->next;
    q = q->next;
    q = q ? q->next : NULL;
  } while (p && q && p != q);
  return p == q ? 1 : 0;
}

void main()
{
  struct Node *t1, *t2;
  int a[5] = {1, 2, 3, 4, 5};
  int b[5] = {6, 7, 8, 9, 10};
  // struct Node *temp;
  create(a, 5);
  create2(b, 5);
  display(first);
  display(second);
  // t1 = first->next->next;
  // t2 = first->next->next->next->next;
  // t2->next = t1;
  // printf("count=%d\n", count(first));
  // printf("sum=%d\n", sum(first));
  // printf("max=%d\n", max(first));
  // temp = search(first, 4);
  // if (temp)
  //   printf("key found\n");
  // else
  //   printf("key not found\n");
  // insert(first, 0, 0);
  // display(first);
  // printf("%d\n", delete(first, 3));
  // printf("%d\n", isSorted(first));
  // removeDuplicate(first);
  // reverse1(first);
  // reverse2(first);
  // reverse3(NULL, first);
  // concatinate(first, second);
  // merge(first, second);
  printf("%d\n", isLoop(first));
  // display(first);
}