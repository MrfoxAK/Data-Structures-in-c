#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct queue
{
     int f,r,size;
     struct node *arr[10];
};

int isEmpty(struct queue *q)
{
     if (q->f == q->r)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

int isFull(struct queue *q)
{
     if (q->r >= q->size)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

void enqueue(struct queue * q,struct node* val){
     if (isFull(q))
     {
          printf("Queue Overflow\n");
     }
     else
     {
          q->r++;
          q->arr[q->r] = val;
     }
}

struct node* dequeue(struct queue *q){
     struct node* val;
     if (isEmpty(q))
     {
          // printf("Queue Underflow\n");
     }
     else
     {
          q->f++;
          val = q->arr[q->f];
     }
     return val;
}

void levelOrder(struct node* root){
     struct node* temp_root = root;
     // printf("Theis %d",temp_root);
     struct queue * q = (struct queue*)malloc(sizeof(struct queue));
     q->size = 10;
     q->f = q->r = -1;
     // q->arr = (struct node*)malloc(sizeof(struct node)*q->size);
     // q->arr[0] = root;
     // printf("%d",q->arr[0]);
     // enqueue(q,temp_root);
     while (temp_root)
     {
          // struct node* pop = dequeue(q);
          printf("%d ",temp_root->data);
          if (temp_root->left!=NULL)
          {
               enqueue(q,temp_root->left);
          }
          if (temp_root->right!=NULL)
          {
               enqueue(q,temp_root->right);
          }
          temp_root = dequeue(q);
     }
     // printf("\nf is %d\n",q->f);
     // printf("\nr is %d\n",q->r);
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
	root->right->left = newNode(115);
	root->right->right = newNode(15);
	root->right->left->left = newNode(112);
	root->right->right->right = newNode(105);
	printf("Level Order traversal of binary tree is \n");
	levelOrder(root);
	return 0;
}