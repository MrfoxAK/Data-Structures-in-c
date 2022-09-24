#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

void Postorder_traversal(struct node * root){
     if (root!=NULL)
     {
          Postorder_traversal(root->left);
          Postorder_traversal(root->right);
          printf("%d ",root->data);
     }
}

struct node* create(){
     int c=1;
     struct node * newnode;
     newnode=(struct node*)malloc(sizeof(struct node));
     printf("Enter data : (-1 for blank)");
     scanf("%d",&c);
     if (c==-1)
     {
          return 0;
     }
     newnode->data=c;
     printf("Enter left child of %d : ",c);
     newnode->left=create();
     printf("Enter right child of %d : ",c);
     newnode->right=create();
     return newnode;
}

int main()
{
     struct node * root = NULL;
     root = create();
     Postorder_traversal(root);
     return 0;
}