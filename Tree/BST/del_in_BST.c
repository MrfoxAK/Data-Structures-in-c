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

struct node* FindMin(struct node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct node* del_in_bst(struct node* root,int data){
     if (root==NULL)
     {
          return NULL;
     }
     else if (data<root->data)
     {
          root->left = del_in_bst(root->left,data);
     }
     else if (data>root->data)
     {
          root->right = del_in_bst(root->right,data);
     }
     else
     {
          // for leaf nodes
          if (root->left == NULL && root->right == NULL)
          {
               free(root);
               root = NULL;
          }

          // for one node
          else if (root->left && root->right==NULL)
          {
               struct node* p;
               root = root->left;
               free(p);
          }
          else if (root->left == NULL && root->right)
          {
               struct node* p;
               root = root->right;
               free(p);
          }
          else{
               // for two nodes
               struct node* temp = FindMin(root->right);
               root->data = temp->data;
               root->right = del_in_bst(root->right,temp->data);
          }
     }
     return root;
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
     root = del_in_bst(root,25);
     inOrder_traversal(root);
     return 0;
}