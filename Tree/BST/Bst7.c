#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

struct node* create_node(int data){
     struct node* new = (struct node*)malloc(sizeof(struct node));
     new->data=data;
     new->left = NULL;
     new->right = NULL;
     return new;
}

struct node* BST(struct node* root, int data){
     if(root == NULL){
          root = create_node(data);
     }
     else if(data < root->data){
          root->left = BST(root->left,data);
     }
     else if(data > root->data){
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

int main()
{
     struct node* root = NULL;
     root = BST(root,1);
     root = BST(root,21);
     root = BST(root,2);
     root = BST(root,25);
     inOrder_traversal(root);
     return 0;
}