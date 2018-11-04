#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

node *prepend(node *head, int val);
node *append(node *head, int val);
node *remove_by_val(node *head, int val);
node *destroy_list(node *head);
void list_info(node *head);
void display_list(node *head);
void display_list_rec(node *head);
void display_reverse(node *head);
int length(node *head);
int length_rec(node *head);

int main()
{
    node *head;

    head = prepend(head, 10);
    head = append(head, 20);
    head = prepend(head, 30);

    // list_info(head);

    display_list(head);

    // display_list_rec(head);
    // printf("NULL\n");

    // printf("NULL <= ");
    // display_reverse(head);
    // printf("\n");

    int len = length(head);
    printf("Length of the list = %d\n", len);

    // int len2 = length_rec(head);
    // printf("Length of the list = %d\n", len2);

    // head = remove_by_val(head, 30);

    head = destroy_list(head);

    display_list(head);

    int len3 = length(head);
    printf("Length of the list = %d\n", len3);

    return 0;
}

node *prepend(node *head, int val)
{
    node *new = malloc(sizeof(node));

    new->data = val;
    new->next = head;

    head = new;

    return head;
}

node *append(node *head, int val)
{
    node *new = malloc(sizeof(node));

    new->data = val;
    new->next = NULL;

    node *iter = head;

    while (iter->next != NULL)
    {
        iter = iter->next;
    }

    iter->next = new;

    return head;
}

node *remove_by_val(node *head, int val)
{
    node *temp = head;

    if (head->data == val)
    {
        head = head->next;
        free(temp);

        return head;
    }

    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    node *temp2 = temp->next;
    temp->next = temp->next->next;

    free(temp2);

    return head;
}

node *destroy_list(node *head)
{
    node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return head;
}

void list_info(node *head)
{
    int i = 0;
    while (head != NULL)
    {
        printf("%d. node's address = %p\n", i, head);
        printf("%d. node's value = %d\n", i, head->data);
        printf("%d. node points to = %p\n", i, head->next);
        head = head->next;
        i++;
    }
}

void display_list(node *head)
{
    while (head != NULL)
    {
        printf("%d => ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

void display_list_rec(node *head)
{
    if (head == NULL)
    {
        return;
    }

    printf("%d => ", head->data);
    display_list_rec(head->next);
}

void display_reverse(node *head)
{
    if (head == NULL)
    {
        return;
    }

    display_reverse(head->next);
    printf("%d <= ", head->data);
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
    {
        return 0;
    }

    return 1 + length_rec(head->next);
}
