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

struct node *insert(struct node *root, int data)
{
     if (root == NULL)
     {
          struct node *n;
          n = (struct node *)malloc(sizeof(struct node));
          n->data = data;
          n->left = NULL;
          n->right = NULL;
          root = n;
          // return root;
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

int max(int a, int b){
     return (a > b) ? a : b;
}

int height(struct node* root){
     if(root==NULL){
          return 0;
     }
     return max(height(root->left),height(root->right))+1;
}

int check_balance(struct node* root){
     if(root==NULL){
          return 1;
     }
     int lh = height(root->left);
     int lr = height(root->right);
     int dif = lh-lr;
     if((abs(dif)==1 || abs(dif==0)) && check_balance(root->left) && check_balance(root->right)){
          return 1;
     }
     else{
          return 0;
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
     inOrder_traversal(root);
     printf("\n%d",check_balance(root));
     return 0;
}