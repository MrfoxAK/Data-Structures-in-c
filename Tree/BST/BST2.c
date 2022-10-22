#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

void inOrder_traversal(struct node * root){
     if (root!=NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ",root->data);
          inOrder_traversal(root->right);
     }
}

struct node* insert(struct node* root,int data){
     struct node* new;
     new = (struct node*)malloc(sizeof(struct node));
     new->data=data;
     new->left=NULL;
     new->right=NULL;
     if (root==NULL)
     {
          root=new;
     }
     else if (data>root->data)
     {
          root->left = insert(root->left,data);
     }
     else
     {
          root->right = insert(root->right,data);
     }
     return root;
}

struct node* search(struct node* root,int data){
     if (root==NULL)
     {
          return NULL;
     }
     if (root->data == data)
     {
          return root;
     }
     else if (data>root->data)
     {
          search(root->left,data);
     }
     else
     {
          search(root->right,data);
     }
}

int main()
{
     struct node* root=NULL;
     root = insert(root, 15);
     root = insert(root, 10);
     root = insert(root, 20);
     root = insert(root, 25);
     root = insert(root, 8);
     root = insert(root, 12);
     inOrder_traversal(root);
     if (search(root,25))
     {
          printf("\nYes\n");
     }
     else
     {
          printf("\nNo\n");
     }
     return 0;
}