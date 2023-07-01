#include <stdio.h>
#include <stdlib.h>

struct Queue
{
     int size;
     int f, r;
     int *arr;
};

int isEmpty(struct Queue *q)
{
     if (q->f == q->r)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

int isFull(struct Queue *q)
{
     if (q->r >= q->size)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

void enqueue(struct Queue *q, int val)
{
     if (isFull(q))
     {
          printf("Queue Overflow\n");
     }
     else
     {
          q->r++;
          q->arr[q->r] = val;
     }
}

int dequeue(struct Queue *q)
{
     int val;
     if (isEmpty(q))
     {
          printf("Queue Underflow\n");
     }
     else
     {
          q->f++;
          val = q->arr[q->f];
     }
     return val;
}

void display(struct Queue *q)
{
     int i = (q->f) + 1;
     while (i <= q->r)
     {
          printf("%d ", q->arr[i]);
          i++;
     }
}

int main()
{
     struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
     q->size = 100;
     q->f = q->r = -1;
     q->arr = (int *)malloc(q->size * sizeof(int));
     int u;
     int i = 0;
     int visited[5] = {0, 0, 0, 0, 0};
     int a[5][5] = {
         {0, 1, 0, 1, 0},
         {1, 0, 0, 0, 0},
         {0, 0, 0, 1, 1},
         {1, 0, 1, 0, 1},
         {0, 0, 1, 1, 0}};
     printf("%d ", i);
     visited[i] = 1;
     enqueue(q, i); // Enqueue i for exploretion
     while (!isEmpty(q))
     {
          int node = dequeue(q);
          for (int j = 0; j < 5; j++)
          {
               if (a[node][j] == 1 && visited[j] == 0)
               {
                    printf("%d ", j);
                    visited[j] = 1;
                    enqueue(q, j);
               }
               if (a[node][j] == 1 && visited[j] == 1)
               {
                    for (int i = 0; i < 5; i++)
                    {
                         
                    }
               }
          }
          // printf("\n");
     }
     return 0;
}