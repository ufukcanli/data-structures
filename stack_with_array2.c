#include <stdio.h>

#define SIZE 10

struct Stack
{
    char items[SIZE];
    int top;
};

typedef struct Stack stack;

void init(stack *stk);
void display(stack *stk);
void push(stack *stk, int val);
int pop(stack *stk);

int main()
{
    stack stack1;

    init(&stack1);

    push(&stack1, 10);
    push(&stack1, 99);
    push(&stack1, 80);
    push(&stack1, 76);
    push(&stack1, 63);
    push(&stack1, 15);
    push(&stack1, 23);
    push(&stack1, 46);
    push(&stack1, 55);
    push(&stack1, 38);
    push(&stack1, 17); // stack overflow!

    display(&stack1);

    int value = pop(&stack1);
    printf("DELETED VALUE: %d\n", value);

    display(&stack1);

    return 0;
}

void init(stack *stk)
{
    stk->top = -1;
}

void display(stack *stk)
{
    if (stk->top == -1)
    {
        printf("NOTHING TO SEE HERE!");
    }
    else
    {
        for (int i = stk->top; i > -1; i--)
        {
            printf("| %d |\n", stk->items[i]);
        }
    }
}

void push(stack *stk, int val)
{
    if (stk->top == SIZE - 1)
    {
        printf("STACK OVERFLOW!\n");
    }
    else
    {
        stk->top++;
        stk->items[stk->top] = val;
    }
}

int pop(stack *stk)
{
    if (stk->top == -1)
    {
        printf("STACK UNDERFLOW!\n");
        
        return -9999;
    }

    int del = stk->items[stk->top];
    stk->top--;

    return del;
}
