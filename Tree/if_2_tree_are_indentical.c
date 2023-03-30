#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

void inOrder_traversal(struct node * root){
     if (root!=NULL)
     {
          inOrder_traversal(root->left);
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

int if_identical(struct node* r1,struct node* r2){
     if (r1==NULL && r2 == NULL)
     {
          return 1;
     }
     if (r1==NULL && r2 != NULL)
     {
          return 0;
     }
     if (r1!=NULL && r2 == NULL)
     {
          return 0;
     }
     if(r1->data!=r2->data){
          return 0;
     }
     return if_identical(r1->left,r2->left) && if_identical(r1->right,r2->right);
}

int main()
{
     struct node* root=NULL;
     root = insert(root, 15);
     root = insert(root, 10);
     root = insert(root, 20);
     root = insert(root, 25);
     root = insert(root, 8);
     root = insert(root, 12);
     inOrder_traversal(root);
     printf("\n");
     struct node* root2=NULL;
     root2 = insert(root2, 15);
     root2 = insert(root2, 10);
     root2 = insert(root2, 20);
     root2 = insert(root2, 25);
     root2 = insert(root2, 8);
     root2 = insert(root2, 12);
     inOrder_traversal(root2);
     printf("\n");
     printf("%d ",if_identical(root,root2));
     return 0;
}