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

struct node* createNode(struct node* n,int data){
     n = (struct node*)malloc(sizeof(struct node));
     n->data = data;
     n->left = NULL;
     n->right = NULL;
     return n;
}

struct node * insert(struct node* root,int data){
     if (root==NULL)
     {
          root = createNode(root,data);
     }
     else if (data<root->data)
     {
          root->left = insert(root->left,data);
     }
     else
     {
          root->right = insert(root->right,data);
     }
     return root;
}

int main()
{
     struct node* root=NULL;
     root = insert(root,12);
     root = insert(root,1);
     root = insert(root,11);
     root = insert(root,22);
     root = insert(root,2);
     root = insert(root,25);
     inOrder_traversal(root);
     return 0;
}