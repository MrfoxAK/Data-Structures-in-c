#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

struct node {
	int data;
	struct node* left;
	struct node* right;
};

int f,r;

struct node** createQueue(){
     struct node** queue = (struct node**)malloc(sizeof(struct node*) * MAX_Q_SIZE);
     f=r=0;
     return queue;
}

void enQueue(struct node** queue, struct node* n){
     queue[r] = n;
     r++;
}

struct node* deQueue(struct node** queue){
     f++;
     return queue[f-1];
}

void levelOrder(struct node* root){
     struct node** queue = createQueue();
     struct node* temp_root = root;
     while (temp_root)
     {
          printf("%d ",temp_root->data);
          if (temp_root->left)
          {
               enQueue(queue,temp_root->left);
          }
          if (temp_root->right)
          {
               enQueue(queue,temp_root->right);
          }
          temp_root = deQueue(queue);
     }
}

struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	printf("Level Order traversal of binary tree is \n");
	levelOrder(root);
	return 0;
}