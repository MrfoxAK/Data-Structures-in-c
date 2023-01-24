#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

struct node *create_node(int data)
{
     struct node *new_node = (struct node *)malloc(sizeof(struct node));
     new_node->left = NULL;
     new_node->right = NULL;
     new_node->data = data;
     return new_node;
}

struct node* insert(struct node* root,int data){
     if (root==NULL)
     {
          root = create_node(data);
     }
     else if (root->data>data)
     {
          root->left = insert(root->left,data);
     }
     else{
          root->right = insert(root->right,data);
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
     struct node *root = NULL;
     root = insert(root,1);
     root = insert(root,0); 
     root = insert(root,132);
     root = insert(root,12);
     // printf("%d\n",root->data);
     inOrder_traversal(root);
     return 0;
}