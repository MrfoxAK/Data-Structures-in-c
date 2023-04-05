#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
     int height;
};

struct node *createNode(int key)
{
     struct node *node = (struct node *)
         malloc(sizeof(struct node));
     node->data = key;
     node->left = NULL;
     node->right = NULL;
     node->height = 1; // new node is initially added at leaf
     return (node);
}

int max(int a, int b)
{
     if (a > b)
     {
          return a;
     }
     else
     {
          return b;
     }
}

int GetHeight(struct node *N)
{
     if (N == NULL)
          return 0;
     // printf("\nH is %d",N->height);
     return N->height;
}

int BF(struct node *root)
{
     if (root == NULL)
     {
          return 0;
     }
     return GetHeight(root->left) - GetHeight(root->right);
}

struct node *leftRotate(struct node *x)
{
     struct node *y = x->right;
     struct node *T2 = y->left;
     y->left = x;
     x->right = T2;
     x->height = max(GetHeight(x->left),
                     GetHeight(x->right)) + 1;
     y->height = max(GetHeight(y->left),
                     GetHeight(y->right)) + 1;
     return y;
}

struct node *rightRotate(struct node *y)
{
     struct node *x = y->left;
     struct node *T2 = x->right;
     x->right = y;
     y->left = T2;
     y->height = max(GetHeight(y->left), GetHeight(y->right)) + 1;
     x->height = max(GetHeight(x->left),GetHeight(x->right)) + 1;
     return x;
}

struct node *insert(struct node *root, int data)
{
     if (root == NULL)
     {
          root = createNode(data);
          return root;
     }
     if (root->data > data)
     {
          root->left = insert(root->left, data);
     }
     else if (root->data < data)
     {
          root->right = insert(root->right, data);
     }
     root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
     int balance = BF(root);
     if (balance > 1 && data < root->left->data)
     {
          return rightRotate(root);
     }
     if (balance < -1 && data > root->right->data)
          return leftRotate(root);
     if (balance > 1 && data > root->left->data)
     {
          root->left = leftRotate(root->left);
          return rightRotate(root);
     }
     if (balance < -1 && data < root->right->data)
     {
          root->right = rightRotate(root->right);
          return leftRotate(root);
     }
     return root;
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

int main()
{
     struct node* root = NULL;
     root = insert(root, 10);
     root = insert(root, 20);
     root = insert(root, 30);
     root = insert(root, 40);
     root = insert(root, 50);
     root = insert(root, 25);
     root = insert(root, 26);
     inOrder(root);
     return 0;
}