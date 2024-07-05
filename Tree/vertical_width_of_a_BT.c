#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int leftSideWidth(struct node* root){
     struct node * temp = root;
     static int total = 0;
     while (temp!=NULL)
     {
          temp = temp->left;
          total += 1;
     }
     return total;
}

int rightSideWidth(struct node* root){
     struct node * temp = root;
     static int total = 0;
     while (temp!=NULL)
     {
          temp = temp->right;
          total += 1;
     }
     return total;
}

int verticalWidth(struct node* root){
     return leftSideWidth(root) + rightSideWidth(root) - 1;
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);
     printf("The Total Vertical Width is %d\n",verticalWidth(root));
	return 0;
}