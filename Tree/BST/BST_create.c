#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

struct node* insert(struct node* root,int data){
     if (root==NULL)
     {
          root = (struct node*)malloc(sizeof(struct node));
          root->data = data;
          root->left=NULL;
          root->right=NULL;
     }
     else if (data<root->data)
     {
          root->left = insert(root->left,data);
     }
     else if (data>root->data)
     {
          root->right = insert(root->right,data);
     }
}

void inOrder_traversal(struct node * root){
     if (root!=NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ",root->data);
          inOrder_traversal(root->right);
     }
}

int main()
{
     struct node* root = NULL;
     root = insert(root,12);
     root = insert(root,1);
     root = insert(root,11);
     root = insert(root,22);
     inOrder_traversal(root);
     return 0;
}