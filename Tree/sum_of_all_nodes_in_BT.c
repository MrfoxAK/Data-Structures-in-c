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
     int c=1,data;
     struct node* new = NULL;
     printf("Enter The Data : ");
     scanf("%d",&data);
     if (data == -1)
     {
          return NULL;
     }
     else{
          new = (struct node*)malloc(sizeof(struct node));
          new->data = data;
          new->left = new->right = NULL;
          printf("For Left of %d ",data);
          new->left = createBT();
          printf("For Right of %d ",data);
          new->right = createBT();
          return new;
     }
}

int Sum(struct node* root){
     if (root == NULL)
     {
          return 0;
     }
     else{
          return root->data + Sum(root->left) + Sum(root->right);
     }
}

int main()
{
     struct node* root = NULL;
     root = createBT();
     // Postorder_traversal(root);
     printf("The Total Sum is %d\n",Sum(root));
     return 0;
}