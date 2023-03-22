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

int max(int a,int b){
     if (a>b)
     {
          return a;
     }
     else{
          return b;
     }
}

struct node* max_diff_BST(struct node* root, int target){
     static int sum;
     int cursum;
     if (root==NULL)
     {
          return 0;
     }
     else if (root->data>target)
     {
          root->left = max_diff_BST(root->left,target);
          sum+=root->data;
     }
     else if (root->data<target)
     {
          root->right = max_diff_BST(root->right,target);
          sum+=root->data;
     }
     printf("%d ",sum);
}

int main()
{
     struct node *root = NULL;
     root = insert(root, 25);
     root = insert(root, 20);
     root = insert(root, 35);
     root = insert(root, 15);
     root = insert(root, 22);
     root = insert(root, 30);
     root = insert(root, 45);
     root = insert(root, 32);
     max_diff_BST(root,32);
     return 0;
}