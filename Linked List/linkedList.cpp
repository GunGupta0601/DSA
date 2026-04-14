#include <iostream>

class Node
{
  int data;
  Node *next;
};

class LinkedList
{
private:
  Node *first;

public:
  LinkedList() { first = NULL; }
  LinkedList(int a[], int n);
  ~LinkedList();

  void display();
  void insert(int index, int x);
  void Delete(int index);
  int length();
};

void LinkedList ::display()
{
  Node *p;
  p = first;
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

void LinkedList ::insert(int index, int x);
{
  Node *t;
  if (index < 0 || index > count(p))
    return;
  t = (Node *)malloc(sizeof(Node));
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

int LinkedList ::Delete(int index)
{
  Node *q = NULL;
  int x = -1;
  if (index < 1 || index > length(p))
  {
    return 0;
  }
  if (index == 1)
  {
    q = first;
    x = first->data;
    first = first->next;
    delete q;
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
    delete p;
    return x;
  }
}

int LinkedList ::length()
{
  Node *p;
  p = first;
  int c = 0;
  while (p != NULL)
  {
    c++;
    p = p->next;
  }
  return c;
}

int mail()
{
  int a[] = {1, 2, 3, 4, 5};
  LinkedList l(a, 5);

  return 0;
}