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

void merge(int A[], int l, int mid, int h)
{
  int i = l, j = mid + 1, k = l;
  int B[100];
  while (i <= mid && j <= h)
  {
    if (A[i] < A[j])
      B[k++] = A[i++];
    else
      B[k++] = A[j++];
  }
  for (; i <= mid; i++)
    B[k++] = A[i];
  for (; j <= h; j++)
    B[k++] = A[j];
  for (i = l; i <= h; i++)
    A[i] = B[i];
}

void ImergeSort(int A[], int n)
{
  int p, l, h, mid, i;
  for (p = 2; p <= n; p = p * 2)
  {
    for (i = 0; i + p - 1 < n; i = i + p)
    {
      l = i;
      h = i + p - 1;
      mid = (l + h) / 2;
      merge(A, l, mid, h);
    }
  }
  if (p / 2 < n)
    merge(A, 0, p / 2 - 1, n - 1);
}

void mergeSort(int A[], int l, int h)
{
  int mid;
  if (l < h)
  {
    mid = (l + h) / 2;
    mergeSort(A, l, mid);
    mergeSort(A, mid + 1, h);
    merge(A, l, mid, h);
  }
}

int main()
{
  int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10, i;
  // int A[] = {3, 7, 9, 10}, n = 4, i;
  // int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, __INT16_MAX__}, n = 11, i;
  // BubbleSort(A, n);
  // InsertionSort(A, n);
  // SelectionSort(A, n);
  // quickSort(A, 0, n - 1);
  // ImergeSort(A, n);
  mergeSort(A, 0, n - 1);
  for (i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}