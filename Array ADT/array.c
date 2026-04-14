#include <stdio.h>
#include <stdlib.h>

struct Array
{
  int *A;
  int size;
  int length;
};

void Resize(struct Array *arr)
{
  int newSize = arr->size * 2;
  int *newArr = (int *)realloc(arr->A, newSize * sizeof(int));
  for (int i = 0; i < arr->length; i++)
  {
    newArr[i] = arr->A[i];
  }
  free(arr->A);
  arr->size = newSize;
  arr->A = newArr;
  newArr = NULL;
}

void Create(struct Array *arr)
{
  int i;
  printf("\nEnter size of the array: ");
  scanf("%d", &arr->size);
  arr->A = (int *)malloc(arr->size * sizeof(int));
  arr->length = 0;
  printf("\nEnter number of elements: ");
  scanf("%d", &arr->length);
  if (arr->length >= arr->size)
    Resize(arr);
  printf("\nEnter all elements: ");
  for (i = 0; i < arr->length; i++)
    scanf("%d", &arr->A[i]);
}

void Display(struct Array arr)
{
  int i;
  printf("\nElements are:\n");
  for (i = 0; i < arr.length; i++)
    printf("%d\t", arr.A[i]);
}

void Append(struct Array *arr, int x)
{
  if (arr->length < arr->size)
    arr->A[arr->length++] = x;
  if (arr->length >= arr->size)
  {
    Resize(arr);
    arr->A[arr->length++] = x;
  }
}

void Insert(struct Array *arr, int index, int x)
{
  int i;
  if (index >= 0 && index < arr->length)
  {
    for (i = arr->length; i > index; i--)
      arr->A[i] = arr->A[i - 1];
    arr->A[index] = x;
    arr->length++;
  }
}

int Delete(struct Array *arr, int index)
{
  int x = 0, i;
  if (index >= 0 && index < arr->length)
  {
    x = arr->A[index];
    for (i = index; i < arr->length - 1; i++)
      arr->A[i] = arr->A[i + 1];
    arr->length--;
    return x;
  }
  return 0;
}

int LinearSearch(struct Array arr, int key)
{
  int i;
  for (i = 0; i < arr.length; i++)
    if (key == arr.A[i])
      return i;
  return -1;
}

void Swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int LinearSearchTransposition(struct Array *arr, int key)
{
  int i;
  for (i = 0; i < arr->length; i++)
    if (key == arr->A[i])
    {
      Swap(&arr->A[i], &arr->A[i - 1]);
      return i - 1;
    }
  return -1;
}

int LinearSearchMoveToFront(struct Array *arr, int key)
{
  int i;
  for (i = 0; i < arr->length; i++)
    if (key == arr->A[i])
    {
      Swap(&arr->A[i], &arr->A[0]);
      return 1;
    }
  return -1;
}

void BubbleSort(struct Array *arr)
{
  int i, j;
  for (i = 0; i < arr->length - 1; i++)
  {
    for (j = 0; j < arr->length - i - 1; j++)
    {
      if (arr->A[j] > arr->A[j + 1])
        Swap(&arr->A[j], &arr->A[j + 1]);
    }
  }
}

int IsSorted(struct Array arr)
{
  int i;
  for (i = 0; i < arr.length - 1; i++)
  {
    if (arr.A[i] < arr.A[i + 1])
      return 1;
  }
  return 0;
}

int BinarySearchIterative(struct Array arr, int key)
{
  if (IsSorted(arr) == 1)
  {
    int l, h, mid;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
      mid = (l + h) / 2;
      if (key == arr.A[mid])
        return mid;
      else if (key < arr.A[mid])
        h = mid - 1;
      else
        l = mid + 1;
    }
    return -1;
  }
}

int BinarySearchRecursive(struct Array arr, int l, int h, int key)
{
  if (IsSorted(arr) == 1)
  {
    int mid;
    if (l <= h)
    {
      mid = (l + h) / 2;
      if (key == arr.A[mid])
        return mid;
      else if (key < arr.A[mid])
        return BinarySearchRecursive(arr, l, mid - 1, key);
      else
        return BinarySearchRecursive(arr, mid + 1, h, key);
    }
    return -1;
  }
}

int Get(struct Array arr, int index)
{
  if (index >= 0 && index < arr.length)
    return arr.A[index];
  return -1;
}

void Set(struct Array *arr, int index, int x)
{
  if (index >= 0 && index < arr->length)
  {
    arr->A[index] = x;
    arr->length++;
  }
}

int Max(struct Array arr)
{
  int i, max = arr.A[0];
  for (i = 1; i < arr.length; i++)
    if (max < arr.A[i])
      max = arr.A[i];
  return max;
}

int Min(struct Array arr)
{
  int i, min = arr.A[0];
  for (i = 1; i < arr.length; i++)
    if (min > arr.A[i])
      min = arr.A[i];
  return min;
}

int Sum(struct Array arr)
{
  int s = 0, i;
  for (i = 0; i < arr.length; i++)
    s += arr.A[i];
  return s;
}

int SumRecursive(struct Array arr, int n)
{
  if (n < 0)
    return 0;
  else
    return SumRecursive(arr, n - 1) + arr.A[n];
}

float Average(struct Array arr)
{
  return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array *arr)
{
  int *B;
  int i, j;
  B = (int *)malloc(arr->length * sizeof(int));
  for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    B[j] = arr->A[i];
  for (i = 0; i < arr->length; i++)
    arr->A[i] = B[i];
}

void Reverse2(struct Array *arr)
{
  int i, j;
  for (i = 0, j = arr->length - 1; i < j; i++, j--)
    Swap(&arr->A[i], &arr->A[j]);
}

void ShiftLeft(struct Array *arr)
{
  int i;
  for (i = 0; i < arr->length - 1; i++)
    arr->A[i] = arr->A[i + 1];
  arr->length--;
}

void RotateLeft(struct Array *arr)
{
  int first = arr->A[0];
  ShiftLeft(arr);
  arr->length++;
  arr->A[arr->length - 1] = first;
}

void ShiftRight(struct Array *arr)
{
  // int i;
  // for (i = arr->length - 1; i > 0; i--)
  //   arr->A[i] = arr->A[i - 1];
  arr->length--;
}

void RotateRight(struct Array *arr)
{
  int last = arr->A[arr->length - 1];
  for (int i = arr->length - 1; i >= 0; i--)
  {
    arr->A[i + 1] = arr->A[i];
  }
  arr->A[0] = last;
}

int main()
{
  struct Array arr;
  int choice, ch = 1, x, index, key;
  Create(&arr);
  do
  {
    printf("\nMenu Driven Program for Array\n");
    printf("\n0. Display\n1. Append\n2. Insert\n3. Delete\n4. Linear Search\n5. Binary Search\n6. Get\n7. Set\n8. Max\n9. Min\n10. Reverse\n11. Shift Left\n12. Shift Right\n13. Rotate Left\n14. Rotate Right\n15. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
      Display(arr);
      break;

    case 1:
      printf("\nEnter element to be appended: ");
      scanf("%d", &x);
      Append(&arr, x);
      Display(arr);
      break;

    case 2:
      printf("\nEnter index of the element to be inserted: ");
      scanf("%d", &index);
      printf("\nEnter the element to be inserted: ");
      scanf("%d", &x);
      Insert(&arr, index, x);
      Display(arr);
      break;

    case 3:
      printf("\nEnter index of the element to be deleted: ");
      scanf("%d", &index);
      printf("\nDeleted element is: %d\n", Delete(&arr, index));
      Display(arr);
      break;

    case 4:
      printf("\nEnter the key element: ");
      scanf("%d", &key);
      printf("\n%d is present at index %d\n", key, LinearSearch(arr, key));
      break;

    case 5:
      printf("\nEnter the key element: ");
      scanf("%d", &key);
      printf("\n%d is present at index %d\n", key, BinarySearchIterative(arr, key));
      break;

    case 6:
      printf("\nEnter index of the element: ");
      scanf("%d", &index);
      printf("\nElement at index %d is %d\n", index, Get(arr, index));
      break;

    case 7:
      printf("\nEnter index of the element: ");
      scanf("%d", &index);
      printf("\nEnter the element: ");
      scanf("%d", &x);
      Set(&arr, index, x);
      Display(arr);
      break;

    case 8:
      printf("\nMaximum number is %d\n", Max(arr));
      break;

    case 9:
      printf("\nMinimum number is %d\n", Min(arr));
      break;

    case 10:
      Reverse(&arr);
      Display(arr);
      break;

    case 11:
      ShiftLeft(&arr);
      Display(arr);
      break;

    case 12:
      ShiftRight(&arr);
      Display(arr);
      break;

    case 13:
      RotateLeft(&arr);
      Display(arr);
      break;

    case 14:
      RotateRight(&arr);
      Display(arr);
      break;

    case 15:
      exit(0);
    }

    printf("\nPress 1 to continue: ");
    scanf("%d", &ch);
  } while (choice >= 0 && choice < 15);
  return 0;
}
