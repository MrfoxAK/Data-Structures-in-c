#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

struct node* createNode(int data){
     struct node * newnode;
     newnode=(struct node*)malloc(sizeof(struct node));
     newnode->left = NULL;
     newnode->right = NULL;
     return newnode;
}

struct node* create(){
     int data;
     struct node * newnode;
     printf("Enter data: (-1 for blank). ");
     scanf("%d",&data);
     if (data == -1){
          return 0;
     }
     else{
          newnode=(struct node*)malloc(sizeof(struct node));
          newnode->data = data;
          printf("for left node of %d ",data);
          newnode->left = create();
          printf("for right node of %d ",data);
          newnode->right = create();
     }
     return newnode;
}

void Postorder_traversal(struct node * root){
     if (root!=NULL)
     {
          Postorder_traversal(root->left);
          Postorder_traversal(root->right);
          printf("%d ",root->data);
     }
}

int main()
{
     struct node* root = NULL;
     root = create();
     Postorder_traversal(root);
     return 0;
}