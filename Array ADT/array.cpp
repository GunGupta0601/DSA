#include <iostream>
using namespace std;

class Array
{
private:
  int *A;
  int size;
  int length;

  void Swap(int *a, int *b)
  {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
  }

public:
  Array()
  {
    size = 10;
    length = 0;
    A = new int[size];
  }

  Array(int sz)
  {
    size = sz;
    length = 0;
    A = new int[size];
  }

  ~Array()
  {
    delete[] A;
  }

  void Resize();
  void Create();
  void Display();
  void Append(int x);
  void Insert(int index, int x);
  int Delete(int index);
  int LinearSearch(int key);
  int LinearSearchTransposition(int key);
  int LinearSearchMoveToFront(int key);
  void BubbleSort();
  int IsSorted();
  int BinarySearchIterative(int key);
  int BinarySearchRecursive(int l, int h, int key);
  int Get(int index);
  void Set(int index, int x);
  int Max();
  int Min();
  int Sum();
  int SumRecursive(int n);
  float Average();
  void Reverse();
  void Reverse2();
  void ShiftLeft();
  void RotateLeft();
  void ShiftRight();
  void RotateRight();
};

void Array::Resize()
{
  int newSize = size * 2;
  int *newArr = new int[newSize];
  for (int i = 0; i < length; i++)
  {
    newArr[i] = A[i];
  }
  delete[] A;
  this->size = newSize;
  A = newArr;
  newArr = NULL;
}

void Array::Create()
{
  int i;
  cout << "\nEnter size of the array: ";
  cin >> size;
  A = new int[size];
  length = 0;
  cout << "\nEnter number of elements: ";
  cin >> length;
  if (length >= size)
    Resize();
  cout << "\nEnter all elements: ";
  for (i = 0; i < length; i++)
    cin >> A[i];
}

void Array::Display()
{
  int i;
  cout << "\nElements are:\n";
  for (i = 0; i < length; i++)
    cout << A[i] << " ";
}

void Array::Append(int x)
{
  if (length < size)
    A[length++] = x;
  if (length >= size)
  {
    Resize();
    A[length++] = x;
  }
}

void Array::Insert(int index, int x)
{
  int i;
  if (index >= 0 && index < length)
  {
    for (i = length; i > index; i--)
      A[i] = A[i - 1];
    A[index] = x;
    length++;
  }
}

int Array::Delete(int index)
{
  int x = 0, i;
  if (index >= 0 && index < length)
  {
    x = A[index];
    for (i = index; i < length - 1; i++)
      A[i] = A[i + 1];
    length--;
    return x;
  }
  return 0;
}

int Array::LinearSearch(int key)
{
  int i;
  for (i = 0; i < length; i++)
    if (key == A[i])
      return i;
  return -1;
}

int Array::LinearSearchTransposition(int key)
{
  int i;
  for (i = 0; i < length; i++)
    if (key == A[i])
    {
      Swap(&A[i], &A[i - 1]);
      return i - 1;
    }
  return -1;
}

int Array::LinearSearchMoveToFront(int key)
{
  int i;
  for (i = 0; i < length; i++)
    if (key == A[i])
    {
      Swap(&A[i], &A[0]);
      return 1;
    }
  return -1;
}

void Array::BubbleSort()
{
  int i, j;
  for (i = 0; i < length - 1; i++)
  {
    for (j = 0; j < length - i - 1; j++)
    {
      if (A[j] > A[j + 1])
        Swap(&A[j], &A[j + 1]);
    }
  }
}

int Array::IsSorted()
{
  int i;
  for (i = 0; i < length - 1; i++)
  {
    if (A[i] < A[i + 1])
      return 1;
  }
  return 0;
}

int Array ::BinarySearchIterative(int key)
{
  if (IsSorted() == 1)
  {
    int l, h, mid;
    l = 0;
    h = length - 1;
    while (l <= h)
    {
      mid = (l + h) / 2;
      if (key == A[mid])
        return mid;
      else if (key < A[mid])
        h = mid - 1;
      else
        l = mid + 1;
    }
    return -1;
  }
}

int Array::BinarySearchRecursive(int l, int h, int key)
{
  if (IsSorted() == 1)
  {
    int mid;
    if (l <= h)
    {
      mid = (l + h) / 2;
      if (key == A[mid])
        return mid;
      else if (key < A[mid])
        return BinarySearchRecursive(l, mid - 1, key);
      else
        return BinarySearchRecursive(mid + 1, h, key);
    }
    return -1;
  }
}

int Array::Get(int index)
{
  if (index >= 0 && index < length)
    return A[index];
  return -1;
}

void Array::Set(int index, int x)
{
  if (index >= 0 && index < length)
  {
    A[index] = x;
    length++;
  }
}

int Array::Max()
{
  int i, max = A[0];
  for (i = 1; i < length; i++)
    if (max < A[i])
      max = A[i];
  return max;
}

int Array::Min()
{
  int i, min = A[0];
  for (i = 1; i < length; i++)
    if (min > A[i])
      min = A[i];
  return min;
}

int Array::Sum()
{
  int s = 0, i;
  for (i = 0; i < length; i++)
    s += A[i];
  return s;
}

int Array::SumRecursive(int n)
{
  if (n < 0)
    return 0;
  else
    return SumRecursive(n - 1) + A[n];
}

float Array::Average()
{
  return (float)Sum() / length;
}

void Array::Reverse()
{
  int *B;
  int i, j;
  B = (int *)malloc(length * sizeof(int));
  for (i = length - 1, j = 0; i >= 0; i--, j++)
    B[j] = A[i];
  for (i = 0; i < length; i++)
    A[i] = B[i];
}

void Array::Reverse2()
{
  int i, j;
  for (i = 0, j = length - 1; i < j; i++, j--)
    Swap(&A[i], &A[j]);
}

void Array::ShiftLeft()
{
  int i;
  for (i = 0; i < length - 1; i++)
    A[i] = A[i + 1];
  length--;
}

void Array::RotateLeft()
{
  int first = A[0];
  ShiftLeft();
  length++;
  A[length - 1] = first;
}

void Array::ShiftRight()
{
  // int i;
  // for (i = length - 1; i > 0; i--)
  //   A[i] = A[i - 1];
  length--;
}

void Array::RotateRight()
{
  int last = A[length - 1];
  for (int i = length - 1; i >= 0; i--)
  {
    A[i + 1] = A[i];
  }
  A[0] = last;
}

int main()
{
  Array arr;
  int choice, ch = 1, x, index, key;
  arr.Create();
  do
  {
    cout << "\nMenu Driven Program for Array\n";
    cout << "\n0. Display\n1. Append\n2. Insert\n3. Delete\n4. Linear Search\n5. Binary Search\n6. Get\n7. Set\n8. Max\n9. Min\n10. Reverse\n11. Shift Left\n12. Shift Right\n13. Rotate Left\n14. Rotate Right\n15. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 0:
      arr.Display();
      break;

    case 1:
      cout << "\nEnter element to be appended: ";
      cin >> x;
      arr.Append(x);
      arr.Display();
      break;

    case 2:
      cout << "\nEnter index of the element to be inserted: ";
      cin >> index;
      cout << "\nEnter the element to be inserted: ";
      cin >> x;
      arr.Insert(index, x);
      arr.Display();
      break;

    case 3:
      cout << "\nEnter index of the element to be deleted: ";
      cin >> index;
      cout << "\nDeleted element is: %d\n", arr.Delete(index);
      arr.Display();
      break;

    case 4:
      cout << "\nEnter the key element: ";
      cin >> key;
      cout << "\n%d is present at index %d\n", key, arr.LinearSearch(key);
      break;

    case 5:
      cout << "\nEnter the key element: ";
      cin >> key;
      cout << "\n%d is present at index %d\n", key, arr.BinarySearchIterative(key);
      break;

    case 6:
      cout << "\nEnter index of the element: ";
      cin >> index;
      cout << "\nElement at index %d is %d\n", index, arr.Get(index);
      break;

    case 7:
      cout << "\nEnter index of the element: ";
      cin >> index;
      cout << "\nEnter the element: ";
      cin >> x;
      arr.Set(index, x);
      arr.Display();
      break;

    case 8:
      cout << "\nMaximum number is %d\n", arr.Max();
      break;

    case 9:
      cout << "\nMinimum number is %d\n", arr.Min();
      break;

    case 10:
      arr.Reverse();
      arr.Display();
      break;

    case 11:
      arr.ShiftLeft();
      arr.Display();
      break;

    case 12:
      arr.ShiftRight();
      arr.Display();
      break;

    case 13:
      arr.RotateLeft();
      arr.Display();
      break;

    case 14:
      arr.RotateRight();
      arr.Display();
      break;

    case 15:
      exit(0);
    }

    cout << "\nPress 1 to continue: ";
  } while (choice >= 0 && choice < 15);
  return 0;
}
