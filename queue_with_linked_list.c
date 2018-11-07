#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
    int length;
};

typedef struct Node node;
typedef struct Queue queue;

void init(queue *qptr);
int empty(queue *qptr);
int full(queue *qptr);
void enQueue(queue *qptr, int val);
int deQueue(queue *qptr);

int main()
{
    queue queue1;
    init(&queue1);

    enQueue(&queue1, 20);
    enQueue(&queue1, 40);
    enQueue(&queue1, 50);

    int value = deQueue(&queue1);
    printf("DELETED VALUE: %d\n", value);

    return 0;
}

void init(queue *qptr)
{
    qptr->front = NULL;
    qptr->rear = NULL;
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
        node *new = malloc(sizeof(node));
        new->data = val;
        new->next = NULL;

        if (empty(qptr))
        {
            qptr->front = new;
            qptr->rear = new;
        }
        else
        {
            qptr->rear = qptr->rear->next;
            qptr->rear = new;
        }

        qptr->length++;
    }
}

int deQueue(queue *qptr)
{
    if (!empty(qptr))
    {
        node *del = qptr->front;
        int value = qptr->front->data;

        qptr->front = qptr->front->next;

        free(del);

        qptr->length--;

        return value;
    }
}
