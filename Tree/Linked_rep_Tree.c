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

int main()
{
     // root node
     // struct node * p;
     // p = (struct node*)malloc(sizeof(struct node));
     // p->data=2;
     // p->left=NULL;
     // p->right=NULL;
     
     // struct node * p1;
     // p1 = (struct node*)malloc(sizeof(struct node));
     // p1->data=23;
     // p1->left=NULL;
     // p1->right=NULL;

     // struct node * p2;
     // p2 = (struct node*)malloc(sizeof(struct node));
     // p2->data=5;
     // p2->left=NULL;
     // p2->right=NULL;

     // // Linking the nodes
     // p->left=p1;
     // p->right=p2;
     
     // using function
     struct node * p = createNode(2);
     struct node * p1 = createNode(32);
     struct node * p2 = createNode(25);

     p->left=p1;
     p->right=p2;

     return 0;
}