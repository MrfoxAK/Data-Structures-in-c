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

struct node* Create_Binary_Tree(){
     int data=1;
     struct node* new=NULL;
     new = (struct node*)malloc(sizeof(struct node));
     printf("Enter data (-1 for NULL) : ");
     scanf("%d",&data);
     if (data==-1)
     {
          return 0;
     }
     else{
          new->data = data;
          printf("For left subtree of %d ",data);
          new->left = Create_Binary_Tree();
          printf("for right subtree of %d ",data);
          new->right = Create_Binary_Tree();
     }
     return new;
}

int main()
{
     struct node * root=NULL;
     root = Create_Binary_Tree();
     inOrder_traversal(root);
     return 0;
}