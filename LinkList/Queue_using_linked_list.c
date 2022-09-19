#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void linklisttreversal(struct Node *ptr)
{
     while (ptr != NULL)
     {
          printf("%d->", ptr->data);
          ptr = ptr->next;
     }
}

void enqueue(int val)
{
     struct Node *n = (struct Node *)malloc(sizeof(struct Node));
     if (n == NULL)
     {
          printf("Queue Overflow\n");
     }
     else
     {
          n->data = val;
          n->next = NULL;
          if (f == NULL)
          {
               f = r = n;
          }
          else
          {
               r->next = n;
               r = n;
          }
     }
}

int dequeue()
{
     int val = -1;
     struct Node *ptr = f;
     if (f == NULL)
     {
          printf("Queue Underflow\n");
     }
     else
     {
          f = f->next;
          val = ptr->data;
          free(ptr);
     }
     return val;
}

int main()
{
     // linklisttreversal(f);
     printf("dequeue %d\n",dequeue());
     enqueue(5);
     enqueue(52);
     enqueue(15);
     enqueue(1);
     printf("dequeue %d\n",dequeue());
     
     linklisttreversal(f);
     return 0;
}