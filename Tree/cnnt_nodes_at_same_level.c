#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

struct node
{
     int data;
     struct node *left;
     struct node *right;
     struct node *newRight;
};

struct node *newNode(int data)
{
     struct node *node = (struct node *)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     node->newRight = NULL;
     return (node);
}

int f, r;

struct node **createQueue()
{
     struct node **queue = (struct node **)malloc(sizeof(struct node *) * MAX_Q_SIZE);
     f = r = 0;
     return queue;
}

int isEmpty(struct node **q)
{
     if (f == r)
          return 1;
     else
          return 0;
}

void enQueue(struct node **q, struct node *n)
{
     q[r] = n;
     r++;
}

struct node *deQueue(struct node **q)
{
     f++;
     return q[f - 1];
}

int Qsize(struct node **q)
{
     int c = 0;
     for (int i = f; i < r; i++)
     {
          c++;
     }
     return c;
}

void connect(struct node *root)
{
     int flag = 0;
     struct node **q = createQueue();
     struct node *curr = NULL;
     enQueue(q, root);
     // enQueue(q,NULL);
     // printf("%d ",Qsize(q));
     while (!isEmpty(q))
     {
          int n = Qsize(q);
          while (n)
          {
               curr = deQueue(q);
               if (n == 1)
               {
                    curr->newRight = NULL;
               }
               else
               {
                    curr->newRight = q[f];
               }
               if (curr->left != NULL)
               {
                    enQueue(q, curr->left);
               }
               if (curr->right != NULL)
               {
                    enQueue(q, curr->right);
               }
               n--;
          }
     }
}

int main()
{
     struct node *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->right->left = newNode(40);
     root->left->right = newNode(5);
     // root->left->right->right = newNode(10);
     printf("Level Order traversal of binary tree is \n");
     // level_order(root);
     connect(root);
     printf("\n new %d\n",root->left->right->newRight->data);
     return 0;
}