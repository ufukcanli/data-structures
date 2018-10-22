#include <stdio.h>
#include <stdlib.h>

// structure of node
struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

// top value declaration
node *top;

// function prototypes
void init();
int empty();
void menu();
void push(int value);
int pop();
void display(node *top);

int main()
{
  int choice, input, deleted, quit = 0;

  do
  {
    menu();
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
      printf("SEE YOU LATER!\n");
      quit = 1;
      break;
    case 1:
      printf("INITIALIZED!\n");
      init();
      break;
    case 2:
      printf("HERE IS THE STACK SO FAR: \n");
      display(top);
      break;
    case 3:
      printf("ENTER A NUMERIC VALUE TO PUSH: ");
      scanf("%d", &input);
      push(input);
      break;
    case 4:
      deleted = pop();
      printf("DELETED VALUE: %d\n", deleted);
      break;
    default:
      printf("SOMETHING WENT WRONG!\n");
    }
  } while (!quit);

  return 0;
}

// initialize the stack
void init()
{
  top = NULL;
}

// checks whether stack is empty or not
int empty()
{
  return top == NULL;
}

// add an element to the stack
void push(int value)
{
  node *temp = malloc(sizeof(node));

  temp->data = value;

  temp->next = top;
  top = temp;
}

// remove an element from the stack
int pop()
{
  node *temp = top;

  int value = top->data;

  top = top->next;

  free(temp);

  return value;
}

// display the stack
void display(node *top)
{
  if (empty())
  {
    printf("EMPTY!\n");
  }
  else
  {
    while (!empty())
    {
      printf("|  %d  |\n", top->data);
      top = top->next;
    }
  }
}

// starting point
void menu()
{
  printf("##### MENU #####\n");
  printf("1) Initialize the stack\n");
  printf("2) Display the stack\n");
  printf("3) Push an element to the stack\n");
  printf("4) Pop an element from the stack\n");
  printf("0) Quit the program\n");
}