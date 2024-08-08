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

int add(struct node* root){
     if (root == NULL)
     {
          return 0;
     }
     else{
          return root->data + add(root->left) + add(root->right);
     }
}

int isSumTree(struct node* root){
     if (root == NULL)
     {
          return 0;
     }
     if (root->left == NULL && root->right == NULL)
     {
          return 1;
     }
     int leftSum = add(root->left);
     int rightSum = add(root->right);
     int total = leftSum+rightSum;
     if (root->data == total)
     {
          if (isSumTree(root->left) && isSumTree(root->right))
          {
               return 1;
          }
     }
     return 0;
}

int main()
{
     struct node* root = NULL;
     root = createBT();
     // Postorder_traversal(root);
     if (isSumTree(root))
          printf("Yes! It's a Sum Tree\n");
     else
          printf("No! It's not a Sum Tree\n");
     
     return 0;
}