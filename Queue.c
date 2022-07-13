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

// #include<stdio.h>
// #include<stdlib.h>
 
// struct queue
// {
//     int size;
//     int f;
//     int r;
//     int* arr;
// };
 
 
// int isEmpty(struct queue *q){
//     if(q->r==q->f){
//         return 1;
//     }
//     return 0;
// }
 
// int isFull(struct queue *q){
//     if(q->r==q->size-1){
//         return 1;
//     }
//     return 0;
// }
 
// void enqueue(struct queue *q, int val){
//     if(isFull(q)){
//         printf("This Queue is full\n");
//     }
//     else{
//         q->r++;
//         q->arr[q->r] = val;
//         printf("Enqued element: %d\n", val);
//     }
// }
 
// int dequeue(struct queue *q){
//     int a = -1;
//     if(isEmpty(q)){
//         printf("This Queue is empty\n");
//     }
//     else{
//         q->f++;
//         a = q->arr[q->f]; 
//     }
//     return a;
// }
 
// int main(){
//     struct queue q;
//     q.size = 4;
//     q.f = q.r = 0;
//     q.arr = (int*) malloc(q.size*sizeof(int));
    
//     // Enqueue few elements
//     enqueue(&q, 12);
//     enqueue(&q, 15);
//     enqueue(&q, 1); 
//     printf("Dequeuing element %d\n", dequeue(&q));
//     printf("Dequeuing element %d\n", dequeue(&q));
//     printf("Dequeuing element %d\n", dequeue(&q)); 
//     enqueue(&q, 45);
//     enqueue(&q, 45);
//     enqueue(&q, 45);
 
//     if(isEmpty(&q)){
//         printf("Queue is empty\n");
//     }
//     if(isFull(&q)){
//         printf("Queue is full\n");
//     }
 
//     return 0;
// }
