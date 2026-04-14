#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  int size;
  int front;
  int rear;
  int *Q;
};

void create(struct Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = -1;
  q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueueFront(struct Queue *q, int x)
{
  if (q->front == q->size - 1)
    printf("Queue is full\n");
  else
  {
    q->front++;
    q->Q[q->front] = x;
  }
}

void enqueueRear(struct Queue *q, int x)
{
  if (q->front == q->size - 1)
    printf("Queue is full\n");
  else
  {
    q->rear++;
    q->Q[q->rear] = x;
  }
}

int dequeueFront(struct Queue *q)
{
  int x = -1;
  if (q->front == q->rear)
    printf("Queue is empty\n");
  else
  {
    q->front++;
    x = q->Q[q->front];
  }
  return x;
}

int dequeueRear(struct Queue *q)
{
  int x = -1;
  if (q->front == q->rear)
    printf("Queue is empty\n");
  else
  {
    q->rear--;
    x = q->Q[q->rear];
  }
  return x;
}

void display(struct Queue q)
{
  int i;
  for (i = q.front + 1; i <= q.rear; i++)
  {
    printf("%d ", q.Q[i]);
  }
  printf("\n");
}

void main()
{
  struct Queue q;
  create(&q, 5);
  enqueueRear(&q, 1);
  enqueueRear(&q, 2);
  enqueueRear(&q, 3);
  enqueueRear(&q, 4);
  enqueueRear(&q, 5);
  display(q);
  printf("%d\n", dequeueFront(&q));
  display(q);
  printf("%d\n", dequeueFront(&q));
  display(q);
}