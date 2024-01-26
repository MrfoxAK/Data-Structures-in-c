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

static int i = 0;
void count(struct node * root, int l, int h){
     if (root!=NULL)
     {
          if(root->data >= l && root->data <= h){
               i++;
          }
          count(root->left,l,h);
          count(root->right,l,h);
     }
}

int main()
{
     struct node* root=NULL;
     root = insert(root, 5);
     root = insert(root, 4);
     root = insert(root, 6);
     root = insert(root, 3);
     root = insert(root, 7);
     // root = insert(root, 100);
     inOrder_traversal(root);
     count(root,2,8);
     printf("\nThe total nodes are : %d\n",i);
     return 0;
}