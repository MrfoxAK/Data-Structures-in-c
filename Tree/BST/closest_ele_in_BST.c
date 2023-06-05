#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

struct node* new(int data){
     struct node* newNode = (struct node*)malloc(sizeof(struct node));
     newNode->data = data;
     newNode->left = NULL;
     newNode->right = NULL;
     return newNode;
}

struct node* BST(struct node* root,int data){
     if (root==NULL)
     {
          root = new(data);
     }
     else if (root->data>data)
     {
          root->left = BST(root->left,data);
     }
     else if (root->data<data)
     {
          root->right = BST(root->right,data);
     }
     return root;
}

void inOrder_traversal(struct node * root){
     if (root!=NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ",root->data);
          inOrder_traversal(root->right);
     }
}

int Closest_Element(struct node* root,int k){
     static int prev = 10;
     int distance;
     if(root!=NULL)
          distance = (k-root->data);
     if(distance==0){
          return 0;
     }
     if(distance < prev){
          prev = distance;
          printf("\n%d\n",prev);
     }
     if(root==NULL){
          return prev;
     }
     else if (root->data > k)
     {
          Closest_Element(root->left,k);
     }
     else if (root->data < k)
     {
          Closest_Element(root->right,k);
     }
}

int main()
{
     struct node* root=NULL;
     root = BST(root, 8);
     root = BST(root, 1);
     root = BST(root, 9);
     root = BST(root, 4);
     root = BST(root, 10);
     root = BST(root, 3);
     inOrder_traversal(root);
     printf("The Element is : %d\n",Closest_Element(root,9));
     return 0;
}