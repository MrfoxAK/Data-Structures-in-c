#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};


struct queue
{
     struct node* arr[100];
     int f,r,size;
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

void level_order(struct node* root){
     struct queue* q=(struct queue*)malloc(sizeof(struct queue));
     q->f = q->r = -1;
     q->size = 10;
     struct node* temp_root = root;
     // enqueue(q,temp_root);
     while (temp_root)
     {
          // struct node* temp = dequeue(q);
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
}

struct node *newNode(int data)
{
     struct node *newNode = (struct node *)malloc(sizeof(struct node));
     newNode->data = data;
     newNode->left = NULL;
     newNode->right = NULL;
     // newNode->height = 1;
     return newNode;
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