#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

struct node *GetNewNode(int data)
{
     struct node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));
     newnode->data = data;
     newnode->left = NULL;
     newnode->right = NULL;
     return newnode;
}

struct node *insert(struct node *root, int data)
{
     if (root == NULL)
     {
          root = GetNewNode(data);
     }
     else if (root->data > data)
     {
          root->left = insert(root->left, data);
     }
     else
     {
          root->right = insert(root->right, data);
     }
     return root;
}

int search(struct node* root,int data){
     if (root==NULL)
     {
          return 0;
     }
     else if (root->data==data)
     {
          return 1;
     }
     else if (data<root->data)
     {
          return search(root->left,data);
     }
     else
     {
          return search(root->right,data);
     }
}

void inOrder_traversal(struct node * root){
     if (root!=NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ",root->data);
          inOrder_traversal(root->right);
     }
}

int isLeaf(struct node* root){
     if (root->left==NULL && root->right==NULL)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

struct node* FindMin(struct node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct node* delete(struct node* root,int data){
     if (root==NULL)
     {
          return NULL;
     }
     else if (data<root->data)
     {
          root->left = delete(root->left,data);
     }
     else if (data>root->data)
     {
          root->right = delete(root->right,data);
     }
     else{
          if (root->left == NULL && root->right == NULL)
          {
               free(root);
               root = NULL;
          }
          else if (root->left && root->right==NULL)
          {
               struct node* temp = root;
               root = root->left;
               free(temp);
          }
          else if (root->left==NULL && root->right)
          {
               struct node* temp = root;
               root = root->right;
               free(temp);
          }
          else{
               struct node* temp = FindMin(root->right);
               root->data = temp->data;
               root->right = delete(root->right,temp->data);
          }
     }
     return root;
}

int main()
{
     struct node *root = NULL;
     root = insert(root, 15);
     root = insert(root, 10);
     root = insert(root, 20);
     root = insert(root, 25);
     root = insert(root, 8);
     root = insert(root, 12);
     if (search(root,12))
     {
          printf("Yes\n");
     }
     else
     {
          printf("No\n");
     }
     inOrder_traversal(root);
     printf("\nAfter del.....\n");
     root=delete(root,12);
     inOrder_traversal(root);
     // printf("\n%d",root->data);
     return 0;
}