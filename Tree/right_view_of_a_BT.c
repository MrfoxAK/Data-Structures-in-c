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

void enQueue(struct node** queue,struct node* n){
     queue[r] = n;
     r++;
}

struct node* deQueue(struct node** queue){
     f++;
     return queue[f-1];
}

int isEmpty(struct node** q){
     if (f == r)
          return 1;
     else
          return 0;
}

int Qsize(struct node** q){
     int c=0;
     for (int i = f; i < r; i++)
     {
          c++;
     }
     return c;
}

void leftView(struct node* root){
     struct node** q = createQueue();
     struct node* curr = NULL;
     enQueue(q,root);
     // enQueue(q,NULL);
     // printf("%d\n",Qsize(q));
     while (!isEmpty(q))
     {
          int n = Qsize(q);
          for (int i = 0; i < n; i++)
          {
               struct node* temp = deQueue(q);
               if (i==n-1)
               {
                    printf("%d ",temp->data);
               }
               if (temp->left!=NULL)
               {
                    enQueue(q,temp->left);
               }
               if (temp->right!=NULL)
               {
                    enQueue(q,temp->right);
               }
          }
     }
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	// root->right->right = newNode(1);
	root->left->right = newNode(5);
	printf("Level Order traversal of binary tree is \n");
	leftView(root);
	return 0;
}