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

int isLeaf(struct node *root)
{
     if (root->left == NULL && root->right == NULL)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

struct node *FindMin(struct node *root)
{
     while (root->left != NULL)
          root = root->left;
     return root;
}

int height(struct node *root)
{
     if (root == NULL)
     {
          return 0;
     }
     else
     {
          int lheight = height(root->left);
          int rheight = height(root->right);
          if (lheight > rheight)
          {
               return (lheight + 1);
          }
          else
          {
               return (rheight + 1);
          }
     }
}

int AVL(struct node *root)
{
     int lh;
     int rh;
     if (root == NULL)
          return 1;
     lh = height(root->left); // left height
     rh = height(root->right); // right height
     if (abs(lh - rh) <= 1 && AVL(root->left) && AVL(root->right))
          return 1;
     return 0;
}

int main()
{
     struct node *root = NULL;
     root = insert(root, 15);
     root = insert(root, 10);
     root = insert(root, 20);
     root = insert(root, 8);
     root = insert(root, 25);
     root = insert(root, 12);
     // root = insert(root, 122);
     // inOrder_traversal(root);
     if(AVL(root)){
          printf("YES\n");
     }
     else
     {
          printf("NO\n");
     }
     return 0;
}