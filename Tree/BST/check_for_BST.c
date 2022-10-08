#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node * left;
     struct node * right;
};

struct node* createNode(int data){
     struct node * Node;
     Node = (struct node*)malloc(sizeof(struct node));
     Node->data=data;
     Node->left=NULL;
     Node->right=NULL;
     return Node;
}

void inOrder_traversal(struct node * root){
     if (root!=NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ",root->data);
          inOrder_traversal(root->right);
     }
}

int isBST(struct node * root){
     static struct node * prev=NULL;
     if (root!=NULL)
     {
          if (!isBST(root->left))
          {
               return 0;
          }
          if (prev!=NULL && root->data<=prev->data)
          {
               return 0;
          }
          prev=root;
          return isBST(root->right);
     }
     else
     {
          return 1;
     }
}

int main()
{
     
     // using function
     struct node * p = createNode(5);
     struct node * p1 = createNode(3);
     struct node * p2 = createNode(6);
     struct node * p3 = createNode(1);
     struct node * p4 = createNode(4);

     p->left=p1;
     p->right=p2;
     p1->left=p3;
     p1->right=p4;

     printf("%d",isBST(p));
     return 0;
}