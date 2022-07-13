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
     // struct Queue q;
     // q.size = 10;
     // q.f=q.r=-1;
     // q.arr=(int*)malloc(q.size*sizeof(int));
     struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
     q->size = 10;
     q->f = q->r = -1;
     q->arr = (int *)malloc(q->size * sizeof(int));
     // printf("the queue is %d\n",isFull(q));
     enqueue(q,2);
     enqueue(q,22);
     enqueue(q,42);
     enqueue(q,422);
     printf("the element is %d\n",dequeue(q));
     printf("the element is %d\n",dequeue(q));
     display(q);
     return 0;
}