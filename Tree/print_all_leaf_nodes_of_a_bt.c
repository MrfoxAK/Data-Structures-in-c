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
     if (root==NULL)
     {
          struct node* n;
          n=(struct node*)malloc(sizeof(struct node));
          n->data=data;
          n->left=NULL;
          n->right=NULL;
          root = n;
          // return root;
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

void print_leaf_nodes(struct node* root){
     if (root == NULL)
     {
          return;
     }
     if (root->left == NULL && root->right == NULL)
     {
          printf("%d ",root->data);
     }
     print_leaf_nodes(root->left);
     print_leaf_nodes(root->right);
}

int main()
{
     struct node* root=NULL;
     root = insert(root, 10);
     root = insert(root, 2);
     root = insert(root, 13);
     root = insert(root, 1);
     root = insert(root, 12);
     root = insert(root, 11);
     root = insert(root, 28);
     root = insert(root, 20);
     root = insert(root, 35);
     // inOrder_traversal(root);
     print_leaf_nodes(root);
     return 0;
}