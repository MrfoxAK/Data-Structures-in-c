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
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int f,r;

struct node** createQueue(){
     struct node** queue = (struct node**)malloc(sizeof(struct node*)*MAX_Q_SIZE);
     f = r =0;
     return queue;
}

void enqueue(struct node** queue,struct node* n){
     queue[r] = n;
     r++;
}

struct node* dequeue(struct node** queue){
     f++;
     return queue[f-1];
}

void level_order(struct node* root){
     struct node* temp_root=root;
     struct node** q = createQueue();
     while (temp_root)
     {
          printf("%d ",temp_root->data);
          if (temp_root->left != NULL)
          {
               enqueue(q,temp_root->left);
          }
          if (temp_root->right != NULL)
          {
               enqueue(q,temp_root->right);
          }
          temp_root=dequeue(q);
     }
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	printf("Level Order traversal of binary tree is \n");
	level_order(root);
	return 0;
}