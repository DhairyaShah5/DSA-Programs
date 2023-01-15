#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

typedef struct tree_node
{
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree;

tree *root = NULL;
bool flag;
int isTrue = 0;

tree *createNode(int data);
void insert(tree *, tree *);
void searchNode(tree *, int key);
void inorder(tree *);

tree *createNode(int data)
{
    // Create a new node
    tree *newNode = (tree *)malloc(sizeof(tree));
    // Assign data to newNode, set left and right children to NULL
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(tree *root, tree *new_node)
{
    if (new_node->data < root->data)
    {
        if (root->left == NULL)
        {
            root->left = new_node;
        }
        else
        {
            insert(root->left, new_node);
        }
    }
    if (new_node->data > root->data)
    {
        if (root->right == NULL)
        {
            root->right = new_node;
        }
        else
        {
            insert(root->right, new_node);
        }
    }
}

// searchNode() will search for the particular node in the binary tree
void searchNode(tree *temp, int value)
{
    // Check whether tree is empty
    flag = false;
    if (root == NULL)
    {
        printf("\n\nCongratulations on finding your first new Pokemon\n\n"); // Tree is empty
    }
    else
    {
        // If value is found in the given binary tree then, set the flag to true
        if (temp->data == value)
        {
            flag = true;
            isTrue = 1;
            return;
        }
        // Search in left subtree
        if (flag == false && temp->left != NULL)
        {
            searchNode(temp->left, value);
        }
        // Search in right subtree
        if (flag == false && temp->right != NULL)
        {
            searchNode(temp->right, value);
        }
    }
}

void inorder(tree *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}