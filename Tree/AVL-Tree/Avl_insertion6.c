#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

struct node *createNode(int data)
{
     struct node *new = (struct node *)malloc(sizeof(struct node));
     new->data = data;
     new->left = new->right = NULL;
     return new;
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

int height(struct node *n)
{
     if (n == NULL)
     {
          return 0;
     }
     else
     {
          return max(height(n->left), height(n->right)) + 1;
     }
}

int BF(struct node *n)
{
     if (n == NULL)
     {
          return 0;
     }
     else
     {
          return (height(n->left) - height(n->right));
     }
}

struct node* leftRotate(struct node* y){
     struct node* x = y->right;
     struct node* t2 = x->left;
     x->left = y;
     y->right = t2;
     return x;
}

struct node* rightRotate(struct node* x){
     struct node* y = x->left;
     struct node* t = y->right;
     y->right = x;
     x->left = t;
     return y;
}

struct node *insert(struct node *root, int data)
{
     if (root == NULL)
     {
          root = createNode(data);
     }
     else if (data < root->data)
     {
          root->left = insert(root->left, data);
     }
     else if (data > root->data)
     {
          root->right = insert(root->right, data);
     }
     int bf = BF(root);
     if (bf > 1 && root->left->data > data)
     {
          return rightRotate(root);
     }
     else if (bf > 1 && data > root->left->data)
     {
          root->left = leftRotate(root->left);
          return rightRotate(root);
     }
     else if (bf<-1 && data>root->right->data)
     {
          return leftRotate(root);
     }
     else if (bf<-1 && data<root->right->data)
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
     struct node *root = NULL;
     /* Constructing tree given in the above figure */
     root = insert(root, 10);
     root = insert(root, 20);
     root = insert(root, 30);
     root = insert(root, 40);
     root = insert(root, 50);
     root = insert(root, 25);
     // root = insert(root, 60);
     /* The constructed AVL Tree would be
             30
            / \
           20 40
           / \	 \
          10 25 50
     */
     printf("Inorder traversal of the constructed AVL"
            " tree is \n");
     inOrder(root);
     printf("\nthe root right data is %d", root->right->right->data);
     return 0;
}