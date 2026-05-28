#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void BubbleSort(int A[], int n)
{
  int i, j, flag = 0;
  for (i = 0; i < n - 1; i++)
  {
    flag = 0;
    for (j = 0; j < n - i - 1; j++)
    {
      if (A[j] > A[j + 1])
      {
        swap(&A[j], &A[j + 1]);
        flag = 1;
      }
    }
    if (flag == 0)
      break;
  }
}

void InsertionSort(int A[], int n)
{
  int i, j, x;
  for (i = 1; i < n; i++)
  {
    j = i - 1;
    x = A[i];
    while (j > -1 && A[j] > x)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = x;
  }
}

void SelectionSort(int A[], int n)
{
  int i, j, k;
  for (i = 0; i < n - 1; i++)
  {
    for (j = k = i; j < n; j++)
    {
      if (A[j] < A[k])
      {
        k = j;
      }
    }
    swap(&A[i], &A[k]);
  }
}

int main()
{
  int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10, i;
  // int A[] = {3, 7, 9, 10}, n = 4, i;
  // BubbleSort(A, n);
  // InsertionSort(A, n);
  SelectionSort(A, n);
  for (i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}