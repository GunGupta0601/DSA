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

int partition(int A[], int l, int h)
{
  int pivot = A[l];
  int i = l, j = h;
  do
  {
    do
    {
      i++;
    } while (A[i] <= pivot);
    do
    {
      j--;
    } while (A[j] > pivot);

    if (i < j)
    {
      swap(&A[i], &A[j]);
    }
  } while (i < j);
  swap(&A[l], &A[j]);
  return j;
}

void quickSort(int A[], int l, int h)
{
  int j;
  if (l < h)
  {
    j = partition(A, l, h);
    quickSort(A, l, j);
    quickSort(A, j + 1, h);
  }
}

int main()
{
  // int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10, i;
  // int A[] = {3, 7, 9, 10}, n = 4, i;
  int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, __INT16_MAX__}, n = 11, i;
  // BubbleSort(A, n);
  // InsertionSort(A, n);
  // SelectionSort(A, n);
  quickSort(A, 0, n);
  for (i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}