#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
     int height;
};

struct node *createNode(int data)
{
     struct node *newNode = (struct node *)malloc(sizeof(struct node));
     newNode->data = data;
     newNode->left = NULL;
     newNode->right = NULL;
     newNode->height = 1;
     return newNode;
}

int getHeight(struct node *n)
{
     if (n == NULL)
     {
          return 0;
     }
     return n->height;
}

int max(int a, int b)
{
     return (a > b) ? a : b;
}

int getBF(struct node* N){
     if (N == NULL)
          return 0;
     return getHeight(N->left) - getHeight(N->right);
}

struct node* leftRotate(struct node* y){
     struct node* x = y->right;
     struct node* t2 = x->left;
     x->left = y;
     y->right = t2;
     x->height = max(getHeight(x->left),getHeight(x->right))+1;
     y->height = max(getHeight(y->left),getHeight(y->right))+1;
     return x;
}

struct node *rightRotate(struct node *x)
{
     struct node *y = x->left;
     struct node *t2 = y->right;
     y->right = x;
     x->left = t2;
     y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
     x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
     return y;
}

struct node* insert(struct node* root,int data){
     if (root==NULL)
     {
          root = createNode(data);
     }
     else if (data>root->data)
     {
          root->right = insert(root->right,data);
     }
     else
     {
          root->left = insert(root->left,data);
     }
     root->height = 1+ max(getHeight(root->left),getHeight(root->right));
     int bf = getBF(root);
     if (bf>1 && data<root->left->data)
     {
          return rightRotate(root);
     }
     else if (bf<-1 && data>root->right->data)
     {
          return leftRotate(root);
     }
     else if (bf>1 && data>root->left->data)
     {
          root->left = leftRotate(root->left);
          return rightRotate(root);
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

// using loop (O)n^2
void levelOrder_traversel(struct node* root,int level){
     if (root==NULL)
     {
          return;
     }
     else if (level==1)
     {
          printf("%d ",root->data);
     }
     else if (level>1)
     {
          levelOrder_traversel(root->left,level-1);
          levelOrder_traversel(root->right,level-1);    
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
     printf("\n");
     levelOrder_traversel(root,3);
     printf("\nThe level order is: \n");
     for (int i = 0; i < getHeight(root)-1; i++)
     {
          levelOrder_traversel(root,i);
     }
     return 0;
}