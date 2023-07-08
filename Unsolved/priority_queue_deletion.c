#include <stdio.h>
#include <stdlib.h>

struct node
{
     int v;
     int w;
};

int size;

struct node *newNode(int v, int w)
{
     struct node *node = (struct node *)malloc(sizeof(struct node));
     node->v = v;
     node->w = w;
     return (node);
}

struct node **PQueue()
{
     struct node **pq = (struct node **)malloc(sizeof(struct node *) * 500);
     size = 0;
     return pq;
}

void insert(struct node **q, struct node *n)
{
     size++;
     int i = size;
     q[i] = n;
     while (i > 1)
     {
          int parent = i / 2;
          if (q[parent]->w > q[i]->w)
          {
               struct node *temp = q[parent];
               q[parent] = q[i];
               q[i] = temp;
               i = parent;
          }
          else
          {
               return;
          }
     }
}

struct node * deletion(struct node **q)
{
     if (size == 0)
     {
          printf("Nothing to delete\n");
     }
     else
     {
          struct node *temp = q[1];
          q[1] = q[size];
          size--;
          int i = 1;
          while (i < size)
          {
               int leftIndex = 2 * i;
               int rightIndex = 2 * i + 1;
               if (leftIndex < size && q[i] > q[leftIndex])
               {
                    struct node *tem = q[leftIndex];
                    q[leftIndex] = q[i];
                    q[i] = tem;
                    i = leftIndex;
               }
               else if (rightIndex < size && q[i] > q[rightIndex])
               {
                    struct node *tem = q[rightIndex];
                    q[rightIndex] = q[i];
                    q[i] = tem;
                    i = rightIndex;
               }
               else
               {
                    return temp;
               }
          }
          return temp;
     }
}

int main()
{
     struct node **q = PQueue();
     insert(q, newNode(0, 50));
     insert(q, newNode(1, 55));
     insert(q, newNode(2, 53));
     insert(q, newNode(3, 52));
     insert(q, newNode(4, 54));
     printf("%d,%d\n", q[1]->v, q[1]->w);
     printf("%d,%d\n", q[2]->v, q[2]->w);
     printf("%d,%d\n", q[3]->v, q[3]->w);
     printf("%d,%d\n", q[4]->v, q[4]->w);
     printf("%d,%d\n", q[5]->v, q[5]->w);
     printf("Now the deletion\n");
     struct node* n1 = deletion(q);
     printf("%d,%d is popped\n",n1->v,n1->w);
     struct node* n2 = deletion(q);
     printf("%d,%d is popped\n",n2->v,n2->w);
     struct node* n3 = deletion(q);
     printf("%d,%d is popped\n",n3->v,n3->w);
     struct node* n4 = deletion(q);
     printf("%d,%d is popped\n",n4->v,n4->w);
     return 0;
}