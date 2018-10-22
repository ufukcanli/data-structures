#include <stdio.h>
#include <stdlib.h>

// structure of node
struct Node
{
  int data;
  struct Node *next;
};

// will make it shorter the code
typedef struct Node node;

// head instance of the list
node *head;

// function prototypes
void init();
void prepend(int val);
void append(int val);
void remove_node(int val);
void display();

int main()
{
  init();

  display();

  append(1);
  prepend(0);
  append(2);
  prepend(-1);

  display();

  remove_node(2); // doesn't work for head node

  display();

  return 0;
}

// it is obvious
void init()
{
  head = NULL;
}

// add a new node at the beginning of the list
void prepend(int val)
{
  node *new = malloc(sizeof(node));

  new->data = val;
  new->next = head;

  head = new;
}

// add a new node at the end of the list
void append(int val)
{
  node *new = malloc(sizeof(node));

  new->data = val;
  new->next = NULL;

  if (head == NULL)
  {
    head = new;
    return;
  }

  node *iter = head;

  while (iter->next != NULL)
  {
    iter = iter->next;
  }

  iter->next = new;
}

// remove a node with a given value
void remove_node(int val)
{
  node *temp = head;

  if (head->data == val)
  {
    head = head->next;
    free(temp);
  }

  while (temp->next->data != val)
  {
    temp = temp->next;
  }

  node *del = temp->next;
  temp->next = del->next;
  free(del);
}

// print the list to the console
void display()
{
  if (head == NULL)
  {
    printf("EMPTY!");
  }

  node *iter = head;

  while (iter != NULL)
  {
    printf("%d => ", iter->data);
    iter = iter->next;
  }

  printf("\n");
}