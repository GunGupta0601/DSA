#include <stdio.h>
#include "queueArray.h"

struct Node *root = NULL;
void treeCreate()
{
  struct Node *p, *t;
  int x;
  struct Queue q;
  create(&q, 100);

  printf("Enter root value:");
  scanf("%d", &x);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = x;
  root->lchild = root->rchild = NULL;
  enqueue(&q, root);

  while (!isEmpty(q))
  {
    p = dequeue(&q);
    printf("Enter left child value of %d:", p->data);
    scanf("%d", &x);
    if (x != -1)
    {
      t = (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      enqueue(&q, t);
    }
    printf("Enter right child value  of %d:", p->data);
    scanf("%d", &x);
    if (x != -1)
    {
      t = (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      enqueue(&q, t);
    }
  }
}

void preorder(struct Node *p)
{
  if (p)
  {
    printf("%d ", root->data);
    preorder(p->lchild);
    preorder(p->rchild);
  }
}

void inorder(struct Node *p)
{
  if (p)
  {
    inorder(p->lchild);
    printf("%d ", root->data);
    inorder(p->rchild);
  }
}

void postorder(struct Node *p)
{
  if (p)
  {
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d ", root->data);
  }
}

int main()
{
  treeCreate();
  preorder(root);
  printf("\nPost Order");
  postorder(root);
  return 0;
}