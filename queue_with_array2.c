#include <stdio.h>

#define SIZE 10

struct Queue
{
    int items[SIZE];
    int front;
    int rear;
    int length;
};

typedef struct Queue queue;

void init(queue *qptr);
int empty(queue *qptr);
int full(queue *qptr);
void enQueue(queue *qptr, int val);
int deQueue(queue *qptr);
void display(queue *qptr);

int main()
{
    queue queue1;
    init(&queue1);

    enQueue(&queue1, 18);
    enQueue(&queue1, 77);
    enQueue(&queue1, 46);
    enQueue(&queue1, 58);
    enQueue(&queue1, 63);
    enQueue(&queue1, 67);

    display(&queue1);

    int value = deQueue(&queue1);
    printf("DELETED VALUE: %d\n", value);

    display(&queue1);

    return 0;
}

void init(queue *qptr)
{
    qptr->front = 0;
    qptr->rear = -1;
    qptr->length = 0;
}

int empty(queue *qptr)
{
    return qptr->length == 0;
}

int full(queue *qptr)
{
    return qptr->length == SIZE;
}

void enQueue(queue *qptr, int val)
{
    if (!full(qptr))
    {
        qptr->rear++;
        qptr->length++;

        if (qptr->rear == SIZE)
        {
            qptr->rear = 0;
        }

        qptr->items[qptr->rear] = val;
    }
}

int deQueue(queue *qptr)
{
    if (!empty(qptr))
    {
        int del = qptr->items[qptr->front];
        qptr->front++;
        qptr->length--;

        if (qptr->front == SIZE)
        {
            qptr->front = 0;
        }

        return del;
    }
}

void display(queue *qptr)
{
    if (qptr->length != 0)
    {
        for (int i = qptr->front; i <= qptr->rear; i++)
        {
            printf("%d <-- ", qptr->items[i]);
        }

        printf("\n");
    }
}
