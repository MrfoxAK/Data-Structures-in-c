#include <stdio.h>
#include <stdlib.h>

struct queue
{
     int *arr;
     int f, r;
     int size;
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

void main()
{
     int value, choice;
     struct queue * q1;
     q1 = (struct queue*)malloc(sizeof(struct queue));
     q1->f=q1->r=-1;
     q1->size=10z;
     q1->arr = (int*)malloc(q1->size*sizeof(int));
     while (1)
     {
          printf("\n\n***** MENU *****\n");
          printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit");
          printf("\nEnter your choice: ");
          scanf("%d", &choice);
          switch (choice)
          {
          case 1:
               printf("Enter the value to be insert: ");
               scanf("%d", &value);
               enQueue(q1,value);
               break;
          case 2:
               printf("\n%d element is removed\n",deQueue(q1));
               break;
          case 3:
               display(q1);
               break;
          case 4:
               exit(0);
          default:
               printf("\nWrong selection!!! Try again!!!");
          }
     }
}