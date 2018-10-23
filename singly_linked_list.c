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
void remove_by_val(int val);
void remove_by_pos(int pos);
void insert(int pos, int val);
void display();
void count();

int main()
{
  init();

  display();

  append(1);
  prepend(0);
  append(2);
  prepend(-1);

  display();

  count();

  remove_by_val(2);
  display();

  insert(2, 4);
  display();

  count();

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

// removes node with a given value
void remove_by_val(int val)
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

// removes node with a given position
void remove_by_pos(int pos)
{
  node *iter = head;

  for (int i = 0; i < pos - 1; i++)
  {
    iter = iter->next;
  }

  node *temp = iter->next;

  iter->next = iter->next->next;

  free(temp);
}

// inserts node at a specific position
void insert(int pos, int val)
{
  node *new = malloc(sizeof(node));

  new->data = val;

  if (pos == 1)
  {
    prepend(val);
    return;
  }

  node *iter = head;

  for (int i = 0; i < pos - 1; i++)
  {
    iter = iter->next;
  }

  new->next = iter->next;
  iter->next = new;
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

// counts nodes in the list
void count()
{
  int counter = 0;

  node *iter = head;

  while (iter != NULL)
  {
    counter++;
    iter = iter->next;
  }

  printf("Length of the list: %d\n", counter);
}
