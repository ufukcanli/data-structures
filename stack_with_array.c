#include <stdio.h>

#define SIZE 10

// structure of stack
struct Stack
{
  int array[SIZE];
  int top;
};

typedef struct Stack stack;

// function prototypes
void init(stack *stk);
void push(stack *stk, int val);
int pop(stack *stk);
int empty(stack *stk);
int full(stack *stk);
void display(stack *stk);

int main()
{
  stack stack1;

  init(&stack1);

  display(&stack1);

  push(&stack1, 100);
  push(&stack1, 200);
  push(&stack1, 300);
  push(&stack1, 400);

  display(&stack1);

  printf("Deleted from stack1: %d\n", pop(&stack1));

  display(&stack1);

  return 0;
}

// initialization
void init(stack *stk)
{
  stk->top = -1;
}

// add an element to the stack
void push(stack *stk, int val)
{
  if (full(stk))
  {
    printf("Stack overflow!\n");
    return;
  }

  stk->top++;
  stk->array[stk->top] = val;
}

// remove an element from the stack
int pop(stack *stk)
{
  if (empty(stk))
  {
    printf("Stack underflow!\n");
    return -9999;
  }

  int del = stk->array[stk->top];
  stk->top--;

  return del;
}

int empty(stack *stk)
{
  return stk->top == -1;
}

int full(stack *stk)
{
  return stk->top == SIZE - 1;
}

void display(stack *stk)
{
  if (empty(stk))
  {
    printf("EMPTY!\n");
  }

  for (int i = stk->top; i > -1; i--)
  {
    printf("| %d |\n", stk->array[i]);
  }
}
