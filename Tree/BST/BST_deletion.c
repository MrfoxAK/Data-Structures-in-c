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
     new->left = NULL;
     new->right = NULL;
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
     while (root->left!=NULL)
     {
          root=root->left;
     }
     return root;
}

struct node* insert(struct node* root,int data){
     if (root==NULL)
     {
          root = createNode(data);
     }
     else if (root->data<data)
     {
          root->right = insert(root->right,data);
     }
     else if (root->data>data)
     {
          root->left = insert(root->left,data);
     }
     return root;
}

struct node* deletion(struct node* root,int data){
     if (root==NULL)
     {
          return NULL;
     }
     else if (root->data<data)
     {
          root->right = deletion(root->right,data);
     }
     else if (root->data>data)
     {
          root->left = deletion(root->left,data);
     }
     else{
          // for leaf nodes
          if (root->left == NULL && root->right == NULL)
          {
               struct node* p = root;
               root = NULL;
               free(p);
          }
          // for those node having one child
          else if (root->left != NULL && root->right == NULL){
               struct node* temp = root;
               root = root->left;
               free(temp);
          }
          else if (root->left == NULL && root->right != NULL){
               struct node* temp = root;
               root = root->right;
               free(temp);
          }
          else{
               struct node* temp;
               temp = findMin(root->right);
               root->data = temp->data;
               root->right = deletion(root->right,temp->data);
          }
     }
     return root;
}

int main()
{
     struct node* root = NULL;
     root = insert(root,10);
     root = insert(root,5);
     root = insert(root,15);
     root = insert(root,1);
     root = insert(root,7);
     root = insert(root,20);
     root = insert(root,12);
     inOrder_traversal(root);
     root = deletion(root,7);
     printf("\n");
     inOrder_traversal(root);
     return 0;
}