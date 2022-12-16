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

struct node* createBT(){
     int data=1;
     printf("Enter data: ");
     scanf("%d",&data);
     if (data==-1)
     {
          return NULL;
     }
     struct node* temp = (struct node*)malloc(sizeof(struct node));
     temp->data = data;
     printf("Enter data of left node of %d ",data);
     temp->left = createBT();
     printf("Enter data of right node of %d ",data);
     temp->right = createBT();
     return temp;
}

int main()
{
     struct node* root = NULL;
     root = createBT();
     Postorder_traversal(root);
     return 0;
}