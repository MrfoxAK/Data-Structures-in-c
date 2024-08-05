#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

int f,r;

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

struct node** createQueue(){
     struct node** queue = (struct node**)malloc(MAX * sizeof(struct node*));
     f = r = 0;
     return queue;
}

int isEmpty(struct node** queue){
     if (f == r)
          return 1;
     else
          return 0;
}

void enQueue(struct node** queue, struct node * node){
     queue[r] = node;
     r++;
}

struct node* deQueue(struct node** queue){
     struct node* temp = queue[f];
     f++;
     return temp;
}

void level_order(struct node* root){
     struct node** queue = createQueue();
     struct node* temp = NULL;
     enQueue(queue,root);
     enQueue(queue,NULL);
     while (!isEmpty(queue))
     {
          temp = deQueue(queue);
          if (temp == NULL)
          {
               if (isEmpty(queue))
               {
                    break;
               }
               else{
                    enQueue(queue,NULL);
                    printf("\n");
               }
          }
          else{
               printf("%d ",temp->data);
               if (temp->left)
               {
                    enQueue(queue,temp->left);
               }
               if (temp->right)
               {
                    enQueue(queue,temp->right);
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
	root->left->right = newNode(5);
	// root->left->right->right = newNode(10);
	printf("Level Order traversal of binary tree is \n");
     level_order(root);
     return 0;
}