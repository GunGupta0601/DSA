#include <stdio.h>
#include <stdlib.h>
struct Stack
{
  int size;
  int top;
  int *S;
};

void Create(struct Stack *st, int size)
{
  st->size = size;
  st->top = -1;
  st->S = (int *)malloc(st->size * sizeof(int));
}

void Push(struct Stack *st, int x)
{
  if (st->top == st->size - 1)
    printf("Stack overflow\n");
  else
  {
    st->top++;
    st->S[st->top] = x;
  }
}

int Pop(struct Stack *st)
{
  int x = -1;
  if (st->top == -1)
    printf("Stack underflow\n");
  else
  {
    x = st->S[st->top];
    st->top--;
  }
  return x;
}

void Display(struct Stack st)
{
  for (int i = 0; i <= st.top; i++)
  {
    printf("%d ", st.S[i]);
  }
  printf("\n");
}

int Peek(struct Stack st, int pos)
{
  int x = -1;
  if (st.top - pos + 1 < 0)
    printf("Invalid position\n");
  else
    x = st.S[st.top - pos + 1];
  return x;
}

int StackTop(struct Stack st)
{
  if (st.top == -1)
    return -1;
  else
    return st.S[st.top];
}

int IsEmpty(struct Stack st)
{
  if (st.top == -1)
    return 1;
  else
    return 0;
}

int IsFull(struct Stack st)
{
  if (st.top == st.size - 1)
    return 1;
  else
    return 0;
}

int main()
{
  struct Stack st;
  Create(&st, 5);
  Push(&st, 1);
  Push(&st, 2);
  Push(&st, 3);
  Push(&st, 4);
  Push(&st, 5);
  Display(st);
  Pop(&st);
  Display(st);
  return 0;
}