////////////////////// CIRCULAR DEQUE /////////////////////
// move pointer by comparator
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void shiftRight(int* pointer)
{
  if ((*pointer)+1 == SIZE)
    *pointer = 0;
  else 
    (*pointer)++;
}

void shiftLeft(int* pointer)
{
  if ((*pointer) == 0)
    *pointer = SIZE-1;
  else 
    (*pointer)--;
}

bool isFull(void)
{
  return (((front == 0) && (rear == SIZE-1)) || (front == rear+1));
}

bool isEmpty(void)
{
  return ((front == -1) || (rear == -1));
}

void display(void)
{
  if (isEmpty())
    printf("empty queue\n");
  else
  {
    int i = front;
    printf("[");
    while (i != rear)
    {
      printf("%d ", queue[i]);
      shiftRight(&i);
    }
    printf("%d]\n", queue[i]);
  }
}
void insertFront(int val)
{
  if (isFull())
    printf("deque full, can't insertFront\n");
  else if (isEmpty())
  {
    front = 0;
    rear = 0;
    queue[front] = val;
  }
  else
  {
    shiftLeft(&front);
    queue[front] = val;
  }
  display();
}
void insertRear(int val)
{
  if (isFull())
    printf("deque full, can't insertRear\n");
  else if (isEmpty())
  {
    front = 0;
    rear = 0;
    queue[front] = val;
  }
  else
  {
    shiftRight(&rear);
    queue[rear] = val;
  }
  display();
}
void removeFront(void)
{
  if (isEmpty())
    printf("deque empty, can't removeFront\n");
  else if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else
  {
    shiftRight(&front);
  }
  display();
}
void removeRear(void)
{
  if (isEmpty())
    printf("deque empty, can't removeRear\n");
  else if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else
  {
    shiftLeft(&rear);
  }
  display();
}

int main(int argc, char const *argv[])
{
  display();

  insertFront(1);
  insertFront(2);
  insertFront(3);
  insertFront(4);
  insertFront(5);
  insertFront(6); //error
  insertFront(7); //error
  
  printf("-----------------\n");
  removeFront();
  removeFront();
  removeFront();
  removeFront();
  removeFront();
  removeFront(); //error

  printf("-----------------\n");

  insertFront(1);
  insertFront(2);
  insertRear(3);
  insertRear(4);
  insertFront(5);
  insertRear(6); //error

  printf("-----------------\n");
  
  removeFront();
  removeFront();
  removeRear();
  removeRear();
  removeFront();
  removeRear(); // error
  return 0;
}