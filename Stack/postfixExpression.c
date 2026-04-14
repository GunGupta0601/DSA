#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
  int size;
  int top;
  char *S;
};

// void Create(struct Stack *st, int size)
// {
//   st->size = size;
//   st->top = -1;
//   st->S = (int *)malloc(st->size * sizeof(int));
// }

void Push(struct Stack *st, char x)
{
  if (st->top == st->size - 1)
    printf("Stack overflow\n");
  else
  {
    st->top++;
    st->S[st->top] = x;
  }
}

char Pop(struct Stack *st)
{
  char x = -1;
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
    printf("%c ", st.S[i]);
  }
  printf("\n");
}

// int Peek(struct Stack st, int pos)
// {
//   int x = -1;
//   if (st.top - pos + 1 < 0)
//     printf("Invalid position\n");
//   else
//     x = st.S[st.top - pos + 1];
//   return x;
// }

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

int IsBalanced(char *exp)
{
  struct Stack st;
  st.size = strlen(exp);
  st.top = -1;
  st.S = (char *)malloc(st.size * sizeof(char));
  for (int i = 0; exp[i] != '\0'; i++)
  {
    if (exp[i] == '(')
      Push(&st, exp[i]);
    else if (exp[i] == ')')
    {
      if (IsEmpty(st))
        return 0;
      Pop(&st);
    }
  }
  return IsEmpty(st) ? 1 : 0;
}

int IsOperand(char x)
{
  if (x == '+' || x == '-' || x == '*' || x == '/')
    return 1;
  else
    return 0;
}

int Precedence(char x)
{
  if (x == '+' || x == '-')
    return 1;
  else if (x == '*' || x == '/')
    return 2;
  return 0;
}

char *ConvertInfixToPostfix(char *infix)
{
  struct Stack st;
  Push(&st, '#');
  int len = strlen(infix);
  char *postfix = (char *)malloc(len + 2 * sizeof(char));
  int i = 0, j = 0;
  while (infix[i] != '\0')
  {
    if (IsOperand(infix[i]))
      postfix[j++] = infix[i++];
    else
    {
      if (Precedence(infix[i]) > Precedence(StackTop(st)))
        Push(&st, infix[i++]);
      else
        postfix[j++] = Pop(&st);
    }
  }
  while (!IsEmpty(st))
    postfix[j++] = Pop(&st);
  postfix[j] = '\0';
  return postfix;
}

int Evaluate(char *postfix)
{
  struct Stack st;
  int x1, x2, r;
  for (int i = 0; postfix[i] != '\0'; i++)
  {
    if (IsOperand(postfix[i]))
      Push(&st, postfix[i] - '0');
    else
    {
      x2 = Pop(&st);
      x1 = Pop(&st);
      switch (postfix[i])
      {
      case '+':
        r = x1 + x2;
        break;
      case '-':
        r = x1 - x2;
        break;
      case '*':
        r = x1 * x2;
        break;
      case '/':
        r = x1 / x2;
        break;
      }
      Push(&st, r);
    }
  }
  return Pop(&st);
}

int main()
{
  // char *exp = "((a+b)*(c-d))";
  // printf("%d ", IsBalanced(exp));
  // char *infix = "a+b*c";
  // char *postfix = ConvertInfixToPostfix(infix);
  // printf("%s ", postfix);
  char *postfix = "35*62/+4-";
  printf("%d ", Evaluate(postfix));

  return 0;
}
