#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

struct node* createNode(int data){
     struct node* new = (struct node*)malloc(sizeof(struct node));
     new->data = data;
     new->left = new->right = NULL;
     return new;
}

void inOrder_traversal(struct node * root){
     if (root!=NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ",root->data);
          inOrder_traversal(root->right);
     }
}

struct node* findMin(struct node* root){
     struct node* root1 = root;
     while (root1->left!=NULL)
     {
          root1 = root1->left;
     }
     return root1;
}

struct node* insert(struct node* root,int data){
     if(root == NULL){
          root = createNode(data);
     }
     else if (data < root->data)
     {
          root->left = insert(root->left, data);
     }
     else if (data > root->data)
     {
          root->right = insert(root->right, data);
     }
     return root;
}

struct node* delete(struct node* root, int data){
     struct node* temp = NULL;
     if(root == NULL){
          return NULL;
     }
     else if(data < root->data){
          root->left = delete(root->left, data);
     }
     else if (data > root->data)
     {
          root->right = delete(root->right, data);
     }
     else{
          if(root->left == NULL && root->right == NULL){
               free(root);
               root = NULL;
          }
          else if (root->left && root->right==NULL)
          {
               temp = root;
               root = root->left;
               free(temp);
          }
          else if (root->right && root->left==NULL)
          {
               temp = root;
               root = root->right;
               free(temp);
          }
          else if (root->left && root->right)
          {
               struct node* min = findMin(root->right);
               root->data = min->data;
               root->right = delete(root->right, min->data);
          }
     }
     return root;
}

int main()
{
     struct node* root = NULL;
     root = insert(root, 15);
     root = insert(root, 10);
     root = insert(root, 20);
     root = insert(root, 25);
     root = insert(root, 8);
     root = insert(root, 12);
     inOrder_traversal(root);
     root = delete(root,20);
     printf("\n");
     inOrder_traversal(root);
     return 0;
}