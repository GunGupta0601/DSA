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

void InsertSorted(struct Array *arr, int x)
{
  int i = arr->length - 1;
  if (arr->length == arr->size)
    return;
  while (i >= 0 && arr->A[i] > x)
  {
    arr->A[i + 1] = arr->A[i];
    i--;
  }
  arr->A[i + 1] = x;
  arr->length++;
}

int IsSortedOrNot(struct Array arr)
{
  int i;
  for (i = 0; i < arr.length; i++)
  {
    if (arr.A[i] > arr.A[i + 1])
      return 0;
  }
  return 1;
}

void Swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void Rearrange(struct Array *arr)
{
  int i, j;
  i = 0;
  j = arr->length - 1;
  while (i < j)
  {
    while (arr->A[i] < 0)
      i++;
    while (arr->A[j] >= 0)
      j--;
    if (i < j)
      Swap(&arr->A[i], &arr->A[j]);
  }
}

struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
  int i, j, k;
  i = j = k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->A[i] < arr2->A[j])
      arr3->A[k++] = arr1->A[i++];
    else
      arr3->A[k++] = arr1->A[j++];
  }
  for (; i < arr1->length; i++)
    arr3->A[k++] = arr1->A[i];
  for (; j < arr2->length; j++)
    arr3->A[k++] = arr2->A[j];
  arr3->length = arr1->length + arr2->length;
  arr3->size = 10;
  return arr3;
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
  int i, j, k;
  i = j = k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->A[i] < arr2->A[j])
      arr3->A[k++] = arr1->A[i++];
    else if (arr1->A[j] < arr2->A[i])
      arr3->A[k++] = arr1->A[j++];
    else
    {
      arr3->A[k++] = arr1->A[i++];
      j++;
    }
  }
  for (; i < arr1->length; i++)
    arr3->A[k++] = arr1->A[i];
  for (; j < arr2->length; j++)
    arr3->A[k++] = arr2->A[j];
  arr3->length = k;
  arr3->size = 10;
  return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
  int i, j, k;
  i = j = k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->A[i] < arr2->A[j])
      i++;
    else if (arr1->A[j] < arr2->A[i])
      j++;
    else if (arr1->A[i] == arr2->A[j])
    {
      arr3->A[k++] = arr1->A[i++];
      j++;
    }
  }
  arr3->length = k;
  arr3->size = 10;
  return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
  int i, j, k;
  i = j = k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->A[i] < arr2->A[j])
      arr3->A[k++] = arr1->A[i++];
    else if (arr1->A[j] < arr2->A[i])
      j++;
    else
    {
      i++;
      j++;
    }
  }
  for (; i < arr1->length; i++)
    arr3->A[k++] = arr1->A[i];
  arr3->length = k;
  arr3->size = 10;
  return arr3;
}

int main()
{
  struct Array arr, arr2, *arr3, *arr4, *arr5;

  Create(&arr);
  Create(&arr2);
  arr3 = Union(&arr, &arr2);
  arr4 = Intersection(&arr, &arr2);
  arr5 = Difference(&arr, &arr2);
  Display(*arr3);
  Display(*arr4);
  Display(*arr5);

  // InsertSorted(&arr, 6);
  // printf("%d\n", IsSortedOrNot(arr));
  // Display(arr);
  // Rearrange(&arr);
  // Display(arr);
  return 0;
}
