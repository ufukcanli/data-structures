#include <stdio.h>
#include <stdlib.h>

// structure of node
struct Node
{
  int data;
  struct Node *next;
};

// structure of list
struct List
{
  struct Node *head;
  struct Node *tail;
  int node_counter;
};

// function prototypes
void init(struct List *list_ptr);
void menu();
void prepend(struct List *list_ptr, int value);
void append(struct List *list_ptr, int value);
void print_list(struct List *list_ptr);
struct Node *find_by_value(struct List *list_ptr, int value);

int main()
{
  struct List linked_list; // creating a linked list instance
  init(&linked_list);      // initialization of the linked list

  int choice, number, quit = 0;
  menu();

  while (!quit)
  {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
      printf("See you later!\n");
      quit = 1;
      break;
    case 1:
      printf("Enter a number (as first node): ");
      scanf("%d", &number);
      prepend(&linked_list, number);
      break;
    case 2:
      printf("Enter a number (as last node): ");
      scanf("%d", &number);
      append(&linked_list, number);
      break;
    case 3:
      printf("Here is the linked list so far: ");
      print_list(&linked_list);
      break;
    default:
      printf("Please enter a valid option :(\n");
    }
  }

  return 0;
}

// initialization
void init(struct List *list_ptr)
{
  list_ptr->head = NULL;
  list_ptr->tail = NULL;
  list_ptr->node_counter = 0;
}

// starting point
void menu()
{
  printf("Singly Linked List Operations\n");
  printf("-----------------------------\n");
  printf("1) Add a new node at the beginning of the list\n");
  printf("2) Add a new node at the end of the list\n");
  printf("3) Print the list from the beginning to the end\n");
  printf("0) Quit the program\n");
}

// add a new node at the beginning of the linked list
void prepend(struct List *list_ptr, int value)
{
  struct Node *new_node;
  new_node = (struct Node *)malloc(sizeof(struct Node));

  new_node->data = value;
  new_node->next = NULL;

  if (list_ptr->node_counter == 0)
  {
    // list is empty so new node is either head and tail
    list_ptr->head = new_node;
    list_ptr->tail = new_node;
  }
  else
  {
    // when the list is not empty
    new_node->next = list_ptr->head;
    list_ptr->head = new_node;
  }

  list_ptr->node_counter++;
}

// add a new node at the end of the linked list
void append(struct List *list_ptr, int value)
{
  struct Node *new_node;
  new_node = (struct Node *)malloc(sizeof(struct Node));

  new_node->data = value;
  new_node->next = NULL;

  if (list_ptr->node_counter == 0)
  {
    // list is empty so new node is either head and tail
    list_ptr->head = new_node;
    list_ptr->tail = new_node;
  }
  else
  {
    // when the list is not empty
    list_ptr->tail->next = new_node;
    list_ptr->tail = new_node;
  }

  list_ptr->node_counter++;
}

// display the list from the beginning to the end
void print_list(struct List *list_ptr)
{
  if (list_ptr->node_counter == 0)
  {
    printf("List is empty!\n");
    return;
  }

  struct Node *iter = list_ptr->head;

  while (iter != NULL)
  {
    printf("%d => ", iter->data);
    iter = iter->next;
  }

  printf("\n");
}

struct Node *find_by_value(struct List *list_ptr, int value)
{
  struct Node *iter = list_ptr->head;

  while (iter != NULL)
  {
    if (iter->data == value)
    {
      break;
    }

    iter = iter->next;
  }

  return iter;
}