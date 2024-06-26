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

void k_distance_from_root(struct node* root, int k){
     int i = 0;
     struct node** q = createQueue();
     // struct node* temp_root = root;
     enQueue(q,root);
     enQueue(q,NULL);
     while (!isEmpty(q))
     {
          struct node* temp_root = deQueue(q);
          if (temp_root==NULL)
          {
               if(isEmpty(q)){
                    break;
               }
               else{
                    enQueue(q,NULL);
                    // printf("\n");
                    i++;
               }
          }
          else{
               if(i == k)
                    printf("%d ",temp_root->data);
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
	root->left = newNode(2);
	root->left->right = newNode(1);
	root->left->right = newNode(1);
	root->left->right->left = newNode(5);
	root->left->right->right = newNode(3);
	// root->left->right->right = newNode(10);
     int k = 3;
	printf("Level Order traversal of binary tree is \n");
	k_distance_from_root(root, k);
	return 0;
}