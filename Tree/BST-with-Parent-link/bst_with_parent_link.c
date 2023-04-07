#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     int color; // 1-red , 0-black
     struct node *left;
     struct node *right;
     struct node *parent;
};

struct node *root = NULL;

struct node *bst(struct node *trav, struct node *temp)
{
     if (trav == NULL)
     {
          return temp;
     }
     if (temp->data < trav->data)
     {
          trav->left = bst(trav->left, temp);
          trav->left->parent = trav;
     }
     else if (temp->data > trav->data)
     {
          trav->right = bst(trav->right, temp);
          trav->right->parent = trav;
     }
     return trav;
}

void inorder(struct node *trav)
{
     if (trav == NULL)
          return;
     inorder(trav->left);
     printf("%d ", trav->data);
     inorder(trav->right);
}

int main()
{
     int n = 7;
     int a[7] = {7, 6, 5, 4, 3, 2, 1};
     for (int i = 0; i < n; i++)
     {
          struct node *temp = (struct node *)malloc(sizeof(struct node));
          temp->left = NULL;
          temp->right = NULL;
          temp->parent = NULL;
          temp->data = a[i];
          temp->color = 1;
          root = bst(root, temp);
     }
     printf("%d\n", root->left->left->parent->data);
     printf("Inorder Traversal of Created Tree\n");
     inorder(root);
     return 0;
}