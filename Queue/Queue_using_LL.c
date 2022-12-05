#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data){
     struct node* newNode = (struct node*)malloc(sizeof(struct node));
     newNode->data = data;
     newNode->next = NULL;
     if (newNode == NULL)
     {
          printf("Queue OverFlow\n");
     }
     else if (front == NULL)
     {
          front = rear = newNode;
     }
     else
     {
          rear->next = newNode;
          rear = newNode;    
     }
}

int dequeue(){
     if (front == NULL)
     {
          printf("Queue UnderFlow\n");
     }
     else
     {
          struct node* temp = front;
          front = front->next;
          int dq = temp->data;
          free(temp);
          return dq;
     }
}

void linklisttreversal(struct node *ptr)
{
     while (ptr != NULL)
     {
          printf("%d->", ptr->data);
          ptr = ptr->next;
     }
     printf("NULL\n");
}

int main()
{
     enqueue(1);
     enqueue(14);
     enqueue(13);
     enqueue(11);
     enqueue(111);
     printf("dequeue %d\n",dequeue());
     printf("dequeue %d\n",dequeue());
     printf("dequeue %d\n",dequeue());
     // dequeue();
     // dequeue();
     linklisttreversal(front);
     return 0;
}