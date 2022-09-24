#include <stdio.h>
#include <stdlib.h>

struct queue
{
     int data;
     struct queue* next;
};

struct queue * f=NULL;
struct queue * r=NULL;

void traversel(){
     struct queue* p=f;
     while (p!=NULL)
     {
          printf("%d->",p->data);
          p=p->next;
     }
}

void enQueue(){
     int data;
     printf("Enter data: ");
     scanf("%d",&data);
     struct queue * newnode=NULL;
     newnode=(struct queue*)malloc(sizeof(struct queue));
     newnode->data=data;
     newnode->next=NULL;
     if (f==NULL && r==NULL)
     {
          f=r=newnode;
     }
     else
     {
          r->next=newnode;
          r=newnode;
     }
}

int deQueue(){
     int data;
     struct queue * p=f;
     if (f==NULL)
     {
          printf("Queue is Already Empty\n");
     }
     else
     {
          data=p->data;
          f=f->next;
     }
     free(p);
     return data;
}

int main()
{
     enQueue();
     enQueue();
     printf("%d removed\n",deQueue());
     printf("%d removed\n",deQueue());
     // deQueue();
     traversel();
     return 0;
}