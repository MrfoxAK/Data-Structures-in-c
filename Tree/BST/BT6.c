#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

struct node* create_node(int data){
     struct node* new = (struct node*)malloc(sizeof(struct node));
     new->data=data;
     new->left = NULL;
     new->right = NULL;
     return new;
}

struct node* create_BT(struct node* root){
     int data;
     printf("Enter data (-1 for blank) : ");
     scanf("%d",&data);
     if (data==-1)
     {
          return 0;
     }
     root = create_node(data);
     printf("For left node of %d, ",data);
     root->left = create_BT(root->left);
     printf("For right node of %d, ",data);
     root->right = create_BT(root->right);
     return root;
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
     struct node* root=NULL;
     root = create_BT(root);
     Postorder_traversal(root);
     return 0;
}