#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

struct node* new(int data){
     struct node* newNode = (struct node*)malloc(sizeof(struct node));
     newNode->data = data;
     newNode->left = NULL;
     newNode->right = NULL;
     return newNode;
}

struct node* BST(struct node* root,int data){
     if (root==NULL)
     {
          root = new(data);
     }
     else if (root->data>data)
     {
          root->left = BST(root->left,data);
     }
     else if (root->data<data)
     {
          root->right = BST(root->right,data);
     }
     return root;
}

void inOrder_traversal(struct node * root){
     if (root!=NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ",root->data);
          inOrder_traversal(root->right);
     }
}

int search(struct node* root,int data){
     if (root==NULL)
     {
          return;
     }
     else if (root->data==data)
     {
          return 1;
     }
     else if (data<root->data)
     {
         return search(root->left,data);
     }
     else
     {
          return search(root->right,data);
     }
}

struct node* Min_dis(struct node* root, int a, int b){
     if(search(root->left,a) && search(root->right,b)){
          printf("(%d)",root->data);
     }
     Min_dis(root->left,a,b);
     Min_dis(root->right,a,b);
}

int main()
{
     struct node* root=NULL;
     root = BST(root, 10);
     root = BST(root, 5);
     root = BST(root, 3);
     root = BST(root, 7);
     root = BST(root, 8);
     root = BST(root, 1);
     root = BST(root, 4);
     root = BST(root, 15);
     root = BST(root, 13);
     root = BST(root, 20);
     // inOrder_traversal(root);
     printf("----- %d",Min_dis(root,1,4));
     return 0;
}