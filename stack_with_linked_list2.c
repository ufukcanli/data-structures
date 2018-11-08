#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
    int length;
};

typedef struct Stack stack;
typedef struct Node node;

void init(stack *stk);
int is_empty(stack *stk);
int is_full(stack *stk);
void push(stack *stk, int val);
int pop(stack *stk);
void display(stack *stk);

int main()
{
    stack stack1;
    init(&stack1);

    push(&stack1, 10);
    push(&stack1, 20);

    int value = pop(&stack1);
    printf("DELETED VALUE: %d\n", value);

    display(&stack1);

    return 0;
}

void init(stack *stk)
{
    stk->top = NULL;
    stk->length = 0;
}

int is_empty(stack *stk)
{
    return stk->length == 0;
}

int is_full(stack *stk)
{
    return stk->length == SIZE;
}

void push(stack *stk, int val)
{
    if (is_full(stk))
    {
        printf("STACK OVERFLOW!\n");
    }
    else
    {
        node *new = malloc(sizeof(node));

        new->data = val;
        new->next = stk->top;

        stk->top = new;

        stk->length++;
    }
}

int pop(stack *stk)
{
    if (is_empty(stk))
    {
        printf("STACK UNDERFLOW!\n");
        return -9999;
    }

    node *del = stk->top;

    int value = stk->top->data;

    stk->top = stk->top->next;

    free(del);
    
    stk->length--;

    return value;
}

void display(stack *stk)
{
    if (is_empty(stk))
    {
        printf("NOTHING TO SEE HERE!");
    }
    else
    {
        while (stk->top != NULL)
        {
            printf("| %d |\n", stk->top->data);
            stk->top = stk->top->next;
        }
    }
}
