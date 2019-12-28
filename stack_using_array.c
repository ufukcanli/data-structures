#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int stack[], int value);
int pop(int stack[]);
void display(int stack[]);
int peek(int stack[]);

void main()
{
    push(stack, 0);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    int deleted = pop(stack);

    display(stack);

    int top = peek(stack);
    printf("\nTOP: %d", top);
}

void push(int stack[], int value)
{
    if (top == MAX - 1)
    {
        printf("\nSTACK OVERFLOW!");
        return;
    }

    stack[++top] = value;
}

int pop(int stack[])
{
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW!");
        return -1;
    }

    int temp = stack[top--];
    return temp;
}

void display(int stack[])
{
    if (top != -1)
    {
        for (int i = top; i > -1; i--)
            printf("| %d | \n", stack[i]);
    }
}

int peek(int stack[])
{
    if (top != -1)
        return stack[top];
}