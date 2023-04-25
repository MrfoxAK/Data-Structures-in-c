#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

struct node *newNode(int data)
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
          root = newNode(data);
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

int ifSubTree(struct node *root, struct node *s)
{
     if (root == NULL)
     {
          return 0;
     }
     if (root->data == s->data)
     {
          if (identicaltree(root, s))
               return 1;
          else
               return 0;
     }
     else
     {
          return ifSubTree(root->left, s) || ifSubTree(root->right, s);
     }
}

int main()
{
     // TREE 1
     /* Construct the following tree
               26
             /   \
           10     3
         /    \     \
       4      6      3
        \
         30
     */
     struct node *T = newNode(26);
     T->right = newNode(3);
     T->right->right = newNode(3);
     T->left = newNode(10);
     T->left->left = newNode(4);
     T->left->left->right = newNode(30);
     T->left->right = newNode(6);

     // TREE 2
     /* Construct the following tree
           10
         /    \
       4      6
        \
         30
     */
     struct node *S = newNode(10);
     S->right = newNode(6);
     S->left = newNode(4);
     S->left->right = newNode(30);
     // S->left->right->right = newNode(60);

     if (ifSubTree(T, S))
          printf("Tree 2 is subtree of Tree 1");
     else
          printf("Tree 2 is not a subtree of Tree 1");
     return 0;
}