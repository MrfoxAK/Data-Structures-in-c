#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

struct node *new(int data)
{
     struct node *newNode = (struct node *)malloc(sizeof(struct node));
     newNode->data = data;
     newNode->left = NULL;
     newNode->right = NULL;
     return newNode;
}

struct node *BST(struct node *root, int data)
{
     if (root == NULL)
     {
          root = new (data);
     }
     else if (root->data > data)
     {
          root->left = BST(root->left, data);
     }
     else if (root->data < data)
     {
          root->right = BST(root->right, data);
     }
     return root;
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

int isSumProperty(struct node *root)
{
     int sum=0;
     if (root==NULL)
     {
          return 1;
     }
     else if(root->left == NULL && root->right == NULL){
          return 1;
     }
     if (root->left)
     {
          sum+=root->left->data;
     }
     if (root->right)
     {
          sum+=root->right->data;
     }
     if (sum == root->data && isSumProperty(root->left) && isSumProperty(root->right))
     {
          return 1;
     }
     else{
          return 0;
     }
}

int main()
{
     struct node *root = NULL;
     root = BST(root, 10);
     root = BST(root, 10);
     root = BST(root, 10);
     // root = BST(root, 1);
     // root = BST(root, 25);
     // inOrder_traversal(root);
     printf("%d ",isSumProperty(root));
     return 0;
}