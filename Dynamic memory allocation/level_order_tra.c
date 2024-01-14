#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

struct node* createNode(int data){
     struct node* new= (struct node*)malloc(sizeof(struct node));
     new->data = data;
     new->left = new->right = NULL;
}

int f,r;

struct node ** createQueue(){
     struct node** q = (struct node**)malloc(sizeof(struct node*)*MAX_Q_SIZE);
     f = r =0;
     return q;
}

struct node* BST(struct node* root, int data){
     if(root == NULL){
          root = createNode(data);
     }
     else if(data < root->data){
          root->left = BST(root->left,data);
     }
     else if(data > root->data){
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

void levelOrder(struct node* root){

}

int main()
{
     struct node* root = NULL;
     root = BST(root,10);
     root = BST(root,5);
     root = BST(root,15);
     root = BST(root,1);
     inOrder_traversal(root);
     return 0;
}