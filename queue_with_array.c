#include <stdio.h>

#define SIZE 5

struct Queue
{
  int front;
  int rear;
  int items[SIZE];
};

typedef struct Queue queue;

void init(queue *qptr);
int full(queue *qptr);
int empty(queue *qptr);
void enQueue(queue *qptr, int val);
void deQueue(queue *qptr);
void display(queue *qptr);

int main()
{
  queue queue1;

  init(&queue1);
  display(&queue1);

  enQueue(&queue1, 0);
  enQueue(&queue1, 1);
  enQueue(&queue1, 2);
  enQueue(&queue1, 3);
  enQueue(&queue1, 4);
  enQueue(&queue1, 5);

  display(&queue1);

  deQueue(&queue1);

  display(&queue1);

  deQueue(&queue1);

  display(&queue1);

  return 0;
}

void init(queue *qptr)
{
  qptr->front = -1;
  qptr->rear = -1;
}

int full(queue *qptr)
{
  return qptr->rear == SIZE - 1;
}

int empty(queue *qptr)
{
  return qptr->front == -1;
}

void enQueue(queue *qptr, int val)
{
  if (full(qptr))
  {
    printf("QUEUE IS FULL!\n");
  }
  else
  {
    if (empty(qptr))
    {
      qptr->front = 0;
    }
    qptr->rear++;
    qptr->items[qptr->rear] = val;
    printf("INSERTED: %d\n", val);
  }
}

void deQueue(queue *qptr)
{
  if (empty(qptr))
  {
    printf("QUEUE IS EMPTY!\n");
  }
  else
  {
    printf("DELETED: %d\n", qptr->items[qptr->front]);
    qptr->front++;

    if (qptr->front > qptr->rear)
    {
      init(qptr);
    }
  }
}

void display(queue *qptr)
{
  if (empty(qptr))
  {
    printf("QUEUE IS EMPTY!\n");
  }
  else
  {
    printf("QUEUE:\n");
    for (int i = qptr->front; i <= qptr->rear; i++)
    {
      printf("%d\t", qptr->items[i]);
    }
    printf("\n");
  }
}
