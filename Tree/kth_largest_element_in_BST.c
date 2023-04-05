#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

int arr[10];
int i=0;

void inOrder_traversal(struct node * root){
     if (root!=NULL)
     {
          inOrder_traversal(root->left);
          arr[i] = root->data;
          i++;
          printf("%d ",root->data);
          inOrder_traversal(root->right);
     }
}

struct node* insert(struct node* root,int data){
     if (root==NULL)
     {
          struct node* n;
          n=(struct node*)malloc(sizeof(struct node));
          n->data=data;
          n->left=NULL;
          n->right=NULL;
          root = n;
          // return root;
     }
     else if (data<root->data)
     {
          root->left = insert(root->left,data);
     }
     else
     {
          root->right = insert(root->right,data);
     }
     return root;
}

int height(struct node* root){
     if (root==NULL)
     {
          return 0;
     }
     else
     {
          int lheight = height(root->left);
          int rheight = height(root->right);
          if (lheight>rheight)
          {
               return (lheight+1);
          }
          else
          {
               return (rheight+1);
          }
     }
}

int kth_largest(struct node* root,int k){
     return arr[i-k];
}

int main()
{
     struct node* root=NULL;
     root = insert(root, 4);
     root = insert(root, 9);
     root = insert(root, 2);
     root = insert(root, 8);
     root = insert(root, 120);
     root = insert(root, 25);
     root = insert(root, 10);
     inOrder_traversal(root);
     int k = 3;
     printf("\nThe %dth largest element is: %d\n",k,kth_largest(root,k));
     return 0;
}