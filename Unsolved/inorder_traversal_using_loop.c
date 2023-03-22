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
     while (1)
     {
          if (root->left!=NULL)
          {
               root = root->left;
               if (root->left == NULL && root->right == NULL)
               {
                    printf("%d ",root->data);
               }
               else if(root->left==NULL && root->right!=NULL) {
                    root = root->right;
               }
               else if(root->left!=NULL && root->right==NULL) {
                    root = root->left;
               }
          }
          if (root->right!=NULL)
          {
               root = root->right;
               if (root->left == NULL && root->right == NULL)
               {
                    printf("%d ",root->data);
               }
               else if(root->left==NULL && root->right!=NULL) {
                    root = root->right;
               }
               else if(root->left!=NULL && root->right==NULL) {
                    root = root->left;
               }
          }
     }
}

int main()
{
     
     // using function
     struct node * p = createNode(4);
     struct node * p1 = createNode(1);
     struct node * p2 = createNode(6);
     struct node * p3 = createNode(5);
     struct node * p4 = createNode(2);
     struct node * p5 = createNode(22);
     struct node * p6 = createNode(24);

     p->left=p1;
     p->right=p2;
     p1->left=p3;
     p1->right=p4;
     p2->left=p5;
     p2->right=p6;

     inOrder_traversal(p);
     return 0;
}