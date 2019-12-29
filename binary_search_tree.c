#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node node;

node *create_node(int value);
node *insert_node(node *root, int value);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
node *find_smallest(node *root);
node *find_largest(node *root);
int size(node *root);
int height(node *root);
node *search(node *root, int value);
node *mirror(node *root);
node *destroy(node *root);

void main()
{
    node *root = NULL;

    root = insert_node(root, 5);
    root = insert_node(root, 75);
}

node *create_node(int value)
{
    node *new_node = malloc(sizeof(node));

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

node *insert_node(node *root, int value)
{
    if (root != NULL)
    {
        if (value < root->data)
            root->left = create_node(value);
        else
            root->right = create_node(value);
    }

    return create_node(value);
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

node *find_smallest(node *root)
{
    if (root == NULL || root->left == NULL)
        return root;

    return find_smallest(root->left);
}

node *find_largest(node *root)
{
    if (root == NULL || root->right == NULL)
        return root;

    return find_largest(root->right);
}

int size(node *root)
{
    if (root == NULL)
        return 0;

    return size(root->left) + 1 + size(root->right);
}

int height(node *root)
{
    if (root == NULL)
        return 0;

    int left_height = height(root->left);
    int right_height = height(root->right);

    if (left_height > right_height)
        return left_height + 1;

    return right_height + 1;
}

node *search(node *root, int value)
{
    if (root == NULL)
        return NULL;

    if (root->data == value)
        return root;

    if (root->data > value)
        return search(root->left, value);

    return search(root->right, value);
}

node *mirror(node *root)
{
    if (root != NULL)
    {
        node *temp_node;

        mirror(root->left);
        mirror(root->right);

        temp_node = root->left;
        root->left = root->right;
        root->right = temp_node;
    }
}

node *destroy(node *root)
{
    if (root != NULL)
    {
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
}