#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node btree;

// function prototypes
btree *create_node(int value);
btree *insert(btree *root, int value);
void preorder(btree *root);
void inorder(btree *root);
void postorder(btree *root);
void mirror(btree *root);
int size(btree *root);

int main()
{
    // root of the tree must be declared before the function calls
    btree *root = NULL;

    root = create_node(100);

    root = insert(root, 300);
    root = insert(root, 200);

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    mirror(root);

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    return 0;
}

btree *create_node(int value)
{
    btree *new_node = malloc(sizeof(btree));

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

btree *insert(btree *root, int value)
{
    // if tree is not empty
    if (root != NULL)
    {
        if (value < root->data)
        {
            // go to the very left of the tree and insert the value
            root->left = insert(root->left, value);
        }
        else
        {
            // go to the very right of the tree and insert the value
            root->right = insert(root->right, value);
        }
    }
    else // if tree is empty
    {
        // create new node and assign it to the root of the tree
        root = create_node(value);
    }

    return root;
}

// preorder traversal operation
void preorder(btree *root)
{
    // if tree is not empty
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// inorder traversal operation
void inorder(btree *root)
{
    // if tree is not empty
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// postorder traversal operation
void postorder(btree *root)
{
    // if tree is not empty
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// swap children of the tree
void mirror(btree *root)
{
    // if tree is empty
    if (root == NULL)
    {
        return;
    }
    else
    {
        btree *temp_node;

        mirror(root->left);
        mirror(root->right);

        temp_node = root->left;
        root->left = root->right;
        root->right = temp_node;
    }
}

// find the size of the tree
int size(btree *root)
{
    if (root == NULL)
        return 0;

    return size(root->left) + 1 + size(root->right);
}

// find the height of the tree
int height(btree *root)
{
    if (root == NULL)
        return -1;

    int left_height = height(root->left);
    int right_height = height(root->right);

    if (left_height > right_height)
        return left_height + 1;
    else
        return right_height + 1;
}