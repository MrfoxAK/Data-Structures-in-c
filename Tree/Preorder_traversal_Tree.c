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

void Preorder_traversal(struct node * root){
     if (root!=NULL)
     {
          printf("%d ",root->data);
          Preorder_traversal(root->left);
          Preorder_traversal(root->right);
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

     p->left=p1;
     p->right=p2;
     p1->left=p3;
     p1->right=p4;

     Preorder_traversal(p);
     return 0;
}