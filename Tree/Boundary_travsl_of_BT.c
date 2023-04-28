#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

struct node *GetNewNode(int data)
{
     struct node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));
     newnode->data = data;
     newnode->left = NULL;
     newnode->right = NULL;
     return newnode;
}

struct node *insert(struct node *root, int data)
{
     if (root == NULL)
     {
          root = GetNewNode(data);
     }
     else if (root->data > data)
     {
          root->left = insert(root->left, data);
     }
     else
     {
          root->right = insert(root->right, data);
     }
     return root;
}

int search(struct node *root, int data)
{
     if (root == NULL)
     {
          return 0;
     }
     else if (root->data == data)
     {
          return 1;
     }
     else if (data < root->data)
     {
          return search(root->left, data);
     }
     else
     {
          return search(root->right, data);
     }
}

void inOrder_traversal(struct node *root)
{
     if (root != NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ", root->data);
          inOrder_traversal(root->right);
     }
}

void leafPart(struct node *root)
{
     if (root != NULL)
     {
          leafPart(root->left);
          if (root->left == NULL && root->right == NULL)
          {
               printf("%d ", root->data);
          }
          leafPart(root->right);
     }
}

void leftPart(struct node *root)
{
     if(root->left == NULL){
          return;
     }
     if (root != NULL)
     {
          printf("%d ", root->data);
          leftPart(root->left);
     }
}

void rightPart(struct node *root)
{
     // if(root->right == NULL){
     //      return;
     // }
     if (root != NULL)
     {
          rightPart(root->right);
          printf("%d ", root->data);
     }
}

void Boundary_traversal(struct node *root)
{
     if (root != NULL)
     {
          leftPart(root);
          leafPart(root);
          rightPart(root);
     }
}

int main()
{
     struct node *root = NULL;
     root = insert(root, 150);
     root = insert(root, 100);
     root = insert(root, 50);
     root = insert(root, 125);
     root = insert(root, 10);
     root = insert(root, 75);
     root = insert(root, 140);
     root = insert(root, 130);
     root = insert(root, 145);
     root = insert(root, 155);
     // root = insert(root, 152);
     // inOrder_traversal(root);
     Boundary_traversal(root);
     return 0;
}