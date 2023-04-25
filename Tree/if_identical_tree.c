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

void inOrder(struct node *root)
{
     if (root != NULL)
     {
          inOrder(root->left);
          printf("%d ", root->data);
          inOrder(root->right);
     }
}

int identicaltree(struct node *root, struct node *s)
{
     if (root == NULL && s != NULL)
     {
          return 0;
     }
     else if (root != NULL && s == NULL)
     {
          return 0;
     }
     else if (root == NULL && s == NULL)
     {
          return 1;
     }
     else if (root->data != s->data)
     {
          return 0;
     }
     else if ((root->data == s->data) && (identicaltree(root->left, s->left) && (identicaltree(root->right, s->right))))
     {
          return 1;
     }
}

int main()
{
     struct node *root = NULL;
     root = insert(root, 15);
     root = insert(root, 10);
     root = insert(root, 20);
     root = insert(root, 25);
     root = insert(root, 8);
     root = insert(root, 12);
     struct node *root1 = NULL;
     root1 = insert(root1, 15);
     root1 = insert(root1, 10);
     root1 = insert(root1, 20);
     root1 = insert(root1, 25);
     root1 = insert(root1, 8);
     root1 = insert(root1, 12);
     // root1 = insert(root1, 1);
     inOrder(root);
     printf("\n");
     inOrder(root1);
     printf("\n%d", identicaltree(root, root1));
     return 0;
}