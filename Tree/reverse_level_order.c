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

int f,r;

struct node** createQueue(){
     struct node** queue  = (struct node**)malloc(sizeof(struct node*)*MAX_Q_SIZE);
     f=r=0;
     return queue;
}

int isEmpty(struct node** q){
     if (f == r)
          return 1;
     else
          return 0;
}

void enQueue(struct node** q, struct node* n){
     q[r] = n;
     r++;
}

struct node* deQueue(struct node** q){
     f++;
     return q[f-1];
}

void level_order(struct node* root){
     int arr[10];
     struct node** q = createQueue();
     struct node* curr = NULL;
     enQueue(q,root);
     enQueue(q,NULL);
     int x=0;
     while (!isEmpty(q))
     {
          curr = deQueue(q);
          if (curr==NULL)
          {
               if (isEmpty(q))
               {
                    break;
               }
               else{
                    enQueue(q,NULL);
                    printf("\n");
               }
          }
          else{
               // printf("%d ",curr->data);
               arr[x] = curr->data;
               x++;
               if (curr->right!=NULL)
               {
                    enQueue(q,curr->right);
               }
               if (curr->left!=NULL)
               {
                    enQueue(q,curr->left);
               }
          }
     }
     for (int i = x-1; i >= 0; i--)
     {
          printf("%d ",arr[i]);
     }
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	// root->left->right->right = newNode(10);
	printf("Level Order traversal of binary tree is \n");
	level_order(root);
	return 0;
}