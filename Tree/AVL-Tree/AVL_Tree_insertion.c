#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
     int height;
};

struct node* newNode(int key){
     struct node *node1 = (struct node *)
         malloc(sizeof(struct node));
     node1->data = key;
     node1->left = NULL;
     node1->right = NULL;
     node1->height = 1;
     return (node1);
}

int getHeight(struct node* root){
     if (root==NULL)
     {
          return 0;
     }
     else
     {
          return root->height;
     }
}

int max(int a,int b){
     if (a>b)
     {
          return a;
     }
     else{
          return b;
     }
}

int BF(struct node* root){
     if (root==NULL)
     {
          return 0;
     }
     else
     {
          return getHeight(root->left) - getHeight(root->right);
     }
}

struct node* rightRotation(struct node* x){
     struct node* y = x->left;
     struct node* t2 = y->right;
     y->right = x;
     x->left = t2;
     x->height = max(getHeight(x->left),getHeight(x->right))+1;
     y->height = max(getHeight(y->left),getHeight(y->right))+1;
     return y;
}

struct node *leftRotate(struct node *x)
{
     struct node *y = x->right;
     struct node *T2 = y->left;
     y->left = x;
     x->right = T2;
     x->height = max(getHeight(x->left),getHeight(x->right))+1;
     y->height = max(getHeight(y->left),getHeight(y->right)) +1;
     return y;
}

struct node* insert(struct node* n,int data){
     if (n==NULL)
     {
          n = newNode(data);
          return n;
     }
     else if (data < n->data)
     {
          n->left = insert(n->left,data);
     }
     else if (data > n->data)
     {
          n->right = insert(n->right,data);
     }
     else
     {
          return n;
     }
     n->height = 1+max(getHeight(n->left),getHeight(n->right));
     int bf = BF(n);
     if (bf>1 && data < n->left->data)
     {
          return rightRotation(n);
     }
     else if (bf>1 && data > n->left->data)
     {
          n->left = leftRotate(n->left);
          return rightRotation(n);
     }
     else if (bf<-1 && data>n->right->data)
     {
          return leftRotate(n);
     }
     else if (bf<-1 && data < n->right->data)
     {
          n->right = rightRotation(n->right);
          return leftRotate(n);
     }
     return n;
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
     return 0;
}
