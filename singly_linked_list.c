#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

node *create_list(node *head, int value);
node *add_first(node *head, int value);
node *add_last(node *head, int value);
node *add_before(node *head, int value, int before);
node *add_after(node *head, int value, int after);
node *remove_first(node *head);
node *remove_last(node *head);
node *remove_node(node *head, int value);
node *destroy_list(node *head);
node *sort_list(node *head);
void display_list(node *head);
void display_list_reverse(node *head);
int length(node *head);
int length_rec(node *head);

void main()
{
    node *head = create_list(head, 0);

    head = add_first(head, 5);

    head = add_last(head, 6);

    head = add_before(head, 10, 6);

    head = add_after(head, 11, 10);

    head = add_before(head, 12, 11);

    head = add_after(head, 13, 12);

    display_list(head);

    // head = remove_first(head);

    // display_list(head);

    // head = remove_last(head);

    // display_list(head);

    // head = remove_node(head, 12);

    // display_list(head);

    // head = destroy_list(head);

    // display_list(head);

    // display_list_reverse(head);

    head = sort_list(head);

    display_list(head);

    printf("Length of the list: %d\n", length(head));
    printf("Length of the list: %d\n", length_rec(head));
}

node *create_list(node *head, int value)
{
    if (head != NULL)
    {
        node *new_node = malloc(sizeof(node));

        new_node->data = value;
        new_node->next = NULL;

        head = new_node;
    }

    return head;
}

void display_list(node *head)
{
    while (head != NULL)
    {
        printf("%d => ", head->data);
        head = head->next;
    }

    printf("\n");
}

node *add_first(node *head, int value)
{
    node *new_node = malloc(sizeof(node));

    new_node->data = value;
    new_node->next = head;

    head = new_node;

    return head;
}

node *add_last(node *head, int value)
{
    node *new_node = malloc(sizeof(node));

    new_node->data = value;
    new_node->next = NULL;

    node *ptr = head;

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new_node;

    return head;
}

node *add_before(node *head, int value, int before)
{
    node *new_node, *prev_node, *ptr;

    new_node = malloc(sizeof(node));
    new_node->data = value;

    ptr = head;

    while (ptr->data != before)
    {
        prev_node = ptr;
        ptr = ptr->next;
    }

    prev_node->next = new_node;
    new_node->next = ptr;

    return head;
}

node *add_after(node *head, int value, int after)
{
    node *new_node, *prev_node, *ptr;

    new_node = malloc(sizeof(node));
    new_node->data = value;

    ptr = head;
    prev_node = ptr;

    while (prev_node->data != after)
    {
        prev_node = ptr;
        ptr = ptr->next;
    }

    prev_node->next = new_node;
    new_node->next = ptr;

    return head;
}

node *remove_first(node *head)
{
    node *temp = head;

    head = head->next;

    free(temp);

    return head;
}

node *remove_last(node *head)
{
    node *temp, *ptr;

    ptr = head;

    while (ptr->next->next != NULL)
        ptr = ptr->next;

    temp = ptr->next->next;

    free(temp);

    ptr->next = NULL;

    return head;
}

node *remove_node(node *head, int value)
{
    node *temp = head;

    if (temp->data == value)
    {
        head = remove_first(head);
        return head;
    }

    node *ptr;

    while (temp->data != value)
    {
        ptr = temp;
        temp = temp->next;
    }

    ptr->next = temp->next;

    free(temp);

    return head;
}

node *destroy_list(node *head)
{
    node *ptr = head;

    while (ptr != NULL)
    {
        head = remove_first(head);
        ptr = head;
    }

    return head;
}

void display_list_reverse(node *head)
{
    if (head == NULL)
        return;

    display_list_reverse(head->next);
    printf("%d => ", head->data);
}

node *sort_list(node *head)
{
    node *ptr1, *ptr2;
    int temp;

    ptr1 = head;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return head;
}

int length(node *head)
{
    int counter = 0;

    while (head != NULL)
    {
        counter++;
        head = head->next;
    }

    return counter;
}

int length_rec(node *head)
{
    if (head == NULL)
        return 0;

    return 1 + length(head->next);
}