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
     struct node** queue = (struct node**)malloc(sizeof(struct node*)*MAX_Q_SIZE);
     f = r = 0;
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

int isEmpty(struct node** queue){
     if (f==r)
     {
          return 1;
     }
     else{
          return 0;
     }
}

void sum_of_all_levels(struct node* root){
     struct node** q = createQueue();
     // struct node* temp_root = root;
     enQueue(q,root);
     enQueue(q,NULL);
     int sum=0;
     while (!isEmpty(q))
     {
          // sum=0;
          struct node* temp_root = deQueue(q);
          if (temp_root==NULL)
          {
               printf("Sum is %d\n",sum);
               if(isEmpty(q)){
                    break;
               }
               else{
                    sum=0;
                    enQueue(q,NULL);
                    printf("\n");
               }
          }
          else{
               // printf("%d ",temp_root->data);
               sum+=temp_root->data;
               if (temp_root->left != NULL)
               {
                    enQueue(q,temp_root->left);
               }
               if (temp_root->right != NULL)
               {
                    enQueue(q,temp_root->right);
               }
          // temp_root = deQueue(q);
          }
     }
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(20);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(-10);
	root->left->right->right = newNode(10);
	printf("Level Order traversal of binary tree is \n");
	sum_of_all_levels(root);
	return 0;
}