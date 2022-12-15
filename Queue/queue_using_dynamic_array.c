#include <stdio.h>
#include <stdlib.h>

struct queue
{
     int * arr;
     int size;
     int f;
     int r;
};

int isEmpty(struct queue *ptr)
{
     if (ptr->f == ptr->r)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

int isFull(struct queue *ptr)
{
     if (ptr->r == ptr->size - 1)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}


void enQueue(struct queue *p, int data)
{
     if (isFull(p))
     {
          printf("Queue is Full\n");
     }
     else
     {
          p->r++;
          p->arr[p->r] = data;
     }
}

int deQueue(struct queue *p)
{
     if (isEmpty(p))
     {
          printf("Queue is Empty\n");
     }
     else
     {
          p->f++;
          int data = p->arr[p->f];
          return data;
     }
}

void display(struct queue* ptr){
     for (int i = ptr->f+1; i <= ptr->r; i++)
     {
          printf("%d ",ptr->arr[i]);
     }
}

int main()
{
     // struct queue q = {{1,2},10,1,3};
     // printf("%d",q.r);
     struct queue * q;
     q = (struct queue*)malloc(sizeof(struct queue));
     q->f = q->r = -1;
     q->size = 5;
     // printf("%d",q->r);
     q->arr = (int*)malloc(sizeof(int)*q->size);
     // q->arr[0] = 1;
     // printf("%d",q->arr[0]);
     enQueue(q,1);
     enQueue(q,111);
     enQueue(q,11);
     printf("%d dequed\n",deQueue(q));
     printf("%d dequed\n",deQueue(q));
     display(q);
     return 0;
}