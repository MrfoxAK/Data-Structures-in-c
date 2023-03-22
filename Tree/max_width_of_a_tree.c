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

int Qsize(struct node** q){
     int c=0;
     for (int i = f; i < r; i++)
     {
          c++;
     }
     return c;
}

void level_order(struct node* root){
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
                    printf("\n");
               }
          }
          else{
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

int max(int a,int b){
     if (a>b)
     {
          return a;
     }
     else{
          return b;
     }
}

// int Max_width(struct node* root){
//      int c=0;
//      struct node** q = createQueue();
//      // struct node* temp_root = root;
//      enQueue(q,root);
//      enQueue(q,NULL);
//      while (!isEmpty(q))
//      {
//           struct node* temp_root = deQueue(q);
//           int n = Qsize(q);
//           c = max(c,n);
//           if (temp_root==NULL)
//           {
//                if(isEmpty(q)){
//                     break;
//                }
//                else{
//                     enQueue(q,NULL);
//                     // printf("\n");
//                }
//           }
//           else{
//                // printf("%d ",temp_root->data);
//                if (temp_root->left != NULL)
//                {
//                     enQueue(q,temp_root->left);
//                }
//                if (temp_root->right != NULL)
//                {
//                     enQueue(q,temp_root->right);
//                }
//           // temp_root = deQueue(q);
//           }
//      }
//      return c-1;
// }

int Max_width(struct node* root){
     int max=0,c=0;
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
                    c=0;
                    int fc=f;
                    struct node* temp=q[f];
                    while (temp!=NULL)
                    {
                         temp=q[fc];
                         fc++;
                         c++;
                    }
                    // printf("%d ",c-1);
                    if (c>max)
                    {
                         max=c;
                    }
                    enQueue(q,NULL);
                    // printf("\n");
               }
          }
          else{
               // printf("%d ",temp_root->data);
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
     return max-1;
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->right = newNode(4);
	root->left->left->left = newNode(41);
	// root->left->right->left = newNode(0);
	// root->left->right->right = newNode(10);
	printf("Level Order traversal of binary tree is \n");
	printf("%d is max width\n",Max_width(root));
	return 0;
}