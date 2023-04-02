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

struct node *createNode(struct node *n, int data)
{
     n = (struct node *)malloc(sizeof(struct node));
     n->data = data;
     n->left = NULL;
     n->right = NULL;
     return n;
}

struct node *insert(struct node *root, int data)
{
     if (root == NULL)
     {
          root = createNode(root, data);
     }
     else if (data < root->data)
     {
          root->left = insert(root->left, data);
     }
     else
     {
          root->right = insert(root->right, data);
     }
     return root;
}

int max(int a,int b){
     return (a > b) ? a : b;
}

int height(struct node *root)
{
     if (root == NULL)
     {
          return 0;
     }
     return 1 + max(height(root->left), height(root->right));
}

int BF(struct node *root)
{
     if (root == NULL)
     {
          return 0;
     }
     else
     {
          return (height(root->left) - height(root->right));
     }
}

struct node *leftRotate(struct node *y)
{
     struct node *x = y->right;
     struct node *t2 = x->left;
     x->left = y;
     y->right = t2;
     // x->height = max(getHeight(x->left),getHeight(x->right))+1;
     // y->height = max(getHeight(y->left),getHeight(y->right))+1;
     return x;
}

struct node *rightRotate(struct node *x)
{
     struct node *y = x->left;
     struct node *t2 = y->right;
     y->right = x;
     x->left = t2;
     // y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
     // x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
     return y;
}

struct node *BuildBalancedTree(struct node *root)
{
     if(root == NULL){
          return NULL;
     }
     if(root->left)
     BuildBalancedTree(root->left);
     if(root->right)
     BuildBalancedTree(root->right);
     int bf = BF(root);
     if (bf>1 && root->right==NULL)
     {
          return rightRotate(root);
     }
     else if (bf<-1 && root->left==NULL)
     {
          return leftRotate(root);
     }
     return root;
     // printf("Of node %d bf is %d\n",root->data,bf);
}

struct node *printBF(struct node *root)
{
     if(root == NULL){
          return NULL;
     }
     if(root->left)
     printBF(root->left);
     if(root->right)
     printBF(root->right);
     int bf = BF(root);
     printf("Of node %d bf is %d\n",root->data,bf);
}

int main()
{
     struct node *root = NULL;
     root = insert(root, 4);
     root = insert(root, 3);
     root = insert(root, 2);
     root = insert(root, 1);
     // root = insert(root, 6);
     root = BuildBalancedTree(root);
     root = printBF(root);
     // inOrder_traversal(root);
     return 0;
}