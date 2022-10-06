#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

void inOrder_traversal(struct node *root)
{
     if (root != NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ", root->data);
          inOrder_traversal(root->right);
     }
}

struct node *Create_Binary_Tree()
{
     int data = 1;
     struct node *new = NULL;
     new = (struct node *)malloc(sizeof(struct node));
     printf("Enter data (-1 for NULL) : ");
     scanf("%d", &data);
     if (data == -1)
     {
          return 0;
     }
     else
     {
          new->data = data;
          printf("For left subtree of %d ", data);
          new->left = Create_Binary_Tree();
          printf("for right subtree of %d ", data);
          new->right = Create_Binary_Tree();
     }
     return new;
}

int check_Full_BT(struct node *root)
{
     // Checking tree emptiness
     if (root == NULL)
          return 1;
     // check for leaf node
     if (root->left==NULL && root->right==NULL)
     {
          return 1;
     }
     if ((root->left) && (root->right))
     {
          return(check_Full_BT(root->left) && check_Full_BT(root->right));
     }
     return 0;
}

int main()
{
     struct node *root = NULL;
     root = Create_Binary_Tree();
     inOrder_traversal(root);
     printf("\n%d",check_Full_BT(root));
     return 0;
}