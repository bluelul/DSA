////////////////////// CIRCULAR QUEUE /////////////////////
// move pointer by comparator
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

bool shiftRight(int* pointer, int obs, bool override)
{
  if (((*pointer)+1 == SIZE) && (obs != 0))
    *pointer = 0;
  else if ((*pointer+1 < SIZE) && \
          ((!override &&(*pointer+1 != obs)) || override))
    (*pointer)++;
  else return false;
  return true;
}
void display(void)
{
  if ((front == -1)&&(rear == -1))
    printf("empty queue\n");
  else
  {
    int i = front;
    printf("[");
    while (i != rear)
    {
      printf("%d ", queue[i]);
      shiftRight(&i, front, false);
    }
    printf("%d]\n", queue[i]);
  }
}
void enqueue(int val)
{
  if ((front == -1)&&(rear == -1))
  {
    front = 0; rear = 0;
  }
  else 
  {
    if (!shiftRight(&rear, front, false))
    {
      printf("ERROR: full queue, can't enqueue\n");
      return;
    }
  }
  queue[rear] = val;
  display();
}
void dequeue(void)
{
  if ((front == -1)&&(rear == -1))
  {
    printf("ERROR: empty queue, can't dequeue\n");
    return;
  }
  else if (front == rear)
  {
    front = -1; rear = -1;
  }
  else shiftRight(&front, rear, true);
  display();
}

int main(int argc, char const *argv[])
{
  display();

  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);
  enqueue(6); //error
  enqueue(7); //error
  
  printf("-----------------\n");
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue(); //error

  printf("-----------------\n");

  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  dequeue();
  dequeue();
  enqueue(5);
  enqueue(6); //error in REGULAR queue
  
  return 0;
}