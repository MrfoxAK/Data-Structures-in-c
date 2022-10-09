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

void inOrder_traversal(struct node *root)
{
     if (root != NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ", root->data);
          inOrder_traversal(root->right);
     }
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

struct node *Iter_insert(struct node *root, int data)
{
     struct node *p = root;
     if (root == NULL)
     {
          root = GetNewNode(data);
          return root;
     }
     // p=root;
     while (1)
     {
          if (data > p->data)
          {
               // p = p->right;
               if (p->right == NULL)
               {
                    p->right = GetNewNode(data);
                    // p=p->right;
                    break;
               }
               else
               {
                    p=p->right;
               }
          }
          else if (data < p->data)
          {
               // p = p->left;
               if (p->left == NULL)
               {
                    p->left = GetNewNode(data);
                    // p=p->left;
                    break;
               }
               else
               {
                    p=p->left;
               }
          }
     }
     return root;
}

int main()
{
     struct node *root = NULL;
     root = Iter_insert(root, 15);
     root = Iter_insert(root, 10);
     root = Iter_insert(root, 20);
     root = Iter_insert(root, 25);
     root = Iter_insert(root, 8);
     root = Iter_insert(root, 12);
     root = Iter_insert(root, 2);
     root = Iter_insert(root, 121);
     if (search(root, 2))
     {
          printf("Yes\n");
     }
     else
     {
          printf("No\n");
     }
     inOrder_traversal(root);
     return 0;
}