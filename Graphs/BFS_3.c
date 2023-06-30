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

void enqueue(struct Queue * q,int val){
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

int dequeue(struct Queue *q){
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

void display(struct Queue *q){
     int i=(q->f)+1;
     while (i<=q->r)
     {
          printf("%d ",q->arr[i]);
          i++;
     }
}

int main()
{
     struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
     q->f = q->r = -1;
     q->size = 100;
     q->arr = (int*)malloc(q->size*sizeof(int));
     int strat=0;
     enqueue(q,strat);
     int visited[7] = {0,0,0,0,0,0,0};
     visited[strat] = 1;
     printf("%d ",strat);
     int a[7][7] = {
          {0,1,1,1,0,0,0},
          {1,0,0,1,0,0,0},
          {1,1,0,1,1,0,0},
          {1,0,1,0,1,0,0},
          {0,0,1,1,0,1,1},
          {0,0,0,0,1,0,0},
          {0,0,0,0,1,0,0}
     };
     while (!isEmpty(q))
     {
          int deq = dequeue(q);
          for (int i = 0; i < 7; i++)
          {
               if(visited[i] == 0 && a[deq][i] == 1){
                    visited[i] = 1;
                    enqueue(q,i);
                    printf("%d ",i);
               }
          }
     }
     return 0;
}