#include <stdio.h>
#include <stdlib.h>
// #include <bits/stdc++.h>
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
     struct node **queue = (struct node *)malloc(sizeof(struct node) * MAX_Q_SIZE);
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

void largest_of_every_level(struct node *root)
{
     int max = 0;
     int i = 0;
     struct node **q = createQueue();
     struct node *curr = NULL;
     enQueue(q, root);
     printf("%d\n", root->data);
     enQueue(q, NULL);
     while (!isEmpty(q))
     {
          curr = deQueue(q);
          if (curr == NULL)
          {
               if (isEmpty(q))
               {
                    break;
               }
               else
               {
                    i = f;
                    max = q[i]->data;
                    while (q[i] != NULL)
                    {
                         if (q[i]->data > max)
                         {
                              max = q[i]->data;
                         }
                         i++;
                    }
                    printf("%d ", max);
                    enQueue(q, NULL);
                    printf("\n");
               }
          }
          else
          {
               if (curr->left != NULL)
               {
                    enQueue(q, curr->left);
               }
               if (curr->right != NULL)
               {
                    enQueue(q, curr->right);
               }
          }
     }
}

int main()
{
     struct node *root = newNode(4);
     root->left = newNode(9);
     root->right = newNode(2);
     root->left->left = newNode(3);
     root->left->right = newNode(5);
     root->right->right = newNode(7);
     // root->left->right->right = newNode(10);
     printf("Level Order traversal of binary tree is \n");
     largest_of_every_level(root);
     return 0;
}