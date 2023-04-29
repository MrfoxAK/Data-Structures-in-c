#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

struct node *newNode(int data)
{
     struct node *node = (struct node *)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     return (node);
}

int f, r;

struct node **createQueue()
{
     struct node **queue = (struct node **)malloc(sizeof(struct node **) * MAX_Q_SIZE);
     f = r = 0;
     return queue;
}

void enqueue(struct node **q, struct node *n)
{
     q[r] = n;
     r++;
}

struct node *dequeue(struct node **q)
{
     f++;
     return q[f - 1];
}

int isEmpty(struct node **q)
{
     if (f == r)
          return 1;
     else
          return 0;
}

void level_order(struct node *root)
{
     struct node **q = createQueue();
     // printf("%d\n",q[f]);
     // enqueue(q,root);
     // printf("%d",q[r]);
     enqueue(q, root);
     enqueue(q, NULL);
     while (!isEmpty(q))
     {
          struct node *temp = dequeue(q);
          if (temp == NULL)
          {
               if (isEmpty(q))
                    break;
               else
               {
                    enqueue(q, NULL);
                    printf("\n");
               }
          }
          else
          {
               printf("%d ", temp->data);
               if (temp->left)
                    enqueue(q, temp->left);
               if (temp->right)
                    enqueue(q, temp->right);
          }
     }
}

int main()
{
     struct node *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     printf("Level Order traversal of binary tree is \n");
     level_order(root);
     return 0;
}