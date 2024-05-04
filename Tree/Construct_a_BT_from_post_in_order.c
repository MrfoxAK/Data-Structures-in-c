#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

struct node* CreateNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void inOrder_traversal(struct node * root){
     if (root!=NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ",root->data);
          inOrder_traversal(root->right);
     }
}

struct node* Helper(int in[],int post[],int in_start, int in_end, int post_start, int post_end)
{
     if (in_start>in_end)
     {
          return NULL;
     }

	int root_val =  post[post_end];
     struct node* root = CreateNode(root_val);

     int i = in_start;
     for (; i < in_end; i++)
     {
          if(in[i] == root_val)
               break;
     }

     int leftTreeSize = i - in_start;
     int rightTreeSize = in_end - i;
     
     root->left = Helper(in, post, in_start, i-1, post_start, post_start+ leftTreeSize-1);
     root->right = Helper(in, post, i+1, in_end, post_end - rightTreeSize, post_end - 1);

     return root;
}

struct node* BuildTree(int in[],int post[],int n)
{
	return Helper(in, post, 0, n-1, 0, n-1);
}

int main()
{
     struct node* root = NULL;
     int n = 10;
     int post[] = {9,1,2,12,7,5,3,11,4,8};
     int in[] = {9,5,1,7,2,12,8,4,3,11};
     root = BuildTree(in, post, n);
     inOrder_traversal(root);
     return 0;
}