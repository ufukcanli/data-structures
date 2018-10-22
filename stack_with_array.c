#include <stdio.h>

#define SIZE 10

// structure of stack
typedef struct
{
  int items[SIZE];
  int top;
} Stack;

// function prototypes
void init(Stack *stack_ptr);
void push(Stack *stack_ptr, int value);
int pop(Stack *stack_ptr);

int main()
{
  Stack stack1, stack2; // create stack instances

  init(&stack1); // initialize its top value as -1
  init(&stack2);

  push(&stack1, 100);
  push(&stack1, 200);
  push(&stack1, 300);

  push(&stack2, 5);
  push(&stack2, 10);
  push(&stack2, 15);

  printf("Deleted from stack1: %d\n", pop(&stack1));
  printf("Deleted from stack2: %d\n", pop(&stack2));

  return 0;
}

// initialization
void init(Stack *stack_ptr)
{
  stack_ptr->top = -1;
}

// add an element to the stack
void push(Stack *stack_ptr, int value)
{
  if (stack_ptr->top == SIZE - 1)
  {
    printf("Stack overflow!\n");
    return;
  }

  stack_ptr->top++;
  stack_ptr->items[stack_ptr->top] = value;
}

// remove an element from the stack
int pop(Stack *stack_ptr)
{
  if (stack_ptr->top == -1)
  {
    printf("Stack underflow!\n");
    return -9999;
  }

  int value = stack_ptr->items[stack_ptr->top];
  stack_ptr->top--;

  return value;
}