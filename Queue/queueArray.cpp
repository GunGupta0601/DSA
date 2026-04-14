#include <iostream>
using namespace std;

class Queue
{
private:
  int size;
  int front;
  int rear;
  int *Q;

public:
  Queue()
  {
    front = rear = -1;
    size = 10;
    Q = new int[size];
  }

  Queue(int size)
  {
    this->size = size;
    front = rear = -1;
    Q = new int[size];
  }

  void enqueue(int x);
  int dequeue();
  void display();

  ~Queue()
  {
    delete[] Q;
  }
};

void Queue::enqueue(int x)
{
  if (front == size - 1)
    printf("Queue is full\n");
  else
  {
    rear++;
    Q[rear] = x;
  }
}

int Queue::dequeue()
{
  int x = -1;
  if (front == rear)
    printf("Queue is empty\n");
  else
  {
    x = Q[front + 1];
    front++;
  }
  return x;
}

void Queue::display()
{
  int i;
  for (i = front + 1; i <= rear; i++)
  {
    printf("%d ", Q[i]);
  }
  printf("\n");
}

int main()
{
  Queue q(5);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.display();
  cout << q.dequeue() << endl;
  q.display();
  return 0;
}