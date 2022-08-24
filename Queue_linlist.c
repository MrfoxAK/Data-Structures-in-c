#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node* next;
};

struct Node* head=NULL;

void enqueue(int val){
     struct Node* temp;
     struct Node* p;
     temp = (struct Node*)malloc(sizeof(struct Node));
     temp->data = val;
     temp->next=NULL;
     if (head==NULL)
     {
          head=temp;
     }
     else
     {
          p=head;
          while (p->next!=NULL)
          {
               p=p->next;
          }
          p->next=temp;
     }
}

int dequeue(){
     struct Node* ptr;
     ptr=head;
     head=head->next;
     int val = ptr->data;
     free(ptr);
     return val;
}

void linklisttreversal(struct Node *ptr)
{
     while (ptr != NULL)
     {
          printf("%d->", ptr->data);
          ptr = ptr->next;
     }
     printf("NULL");
}

int main()
{
     enqueue(14);
     enqueue(144);
     enqueue(1444);
     enqueue(12);
     printf("element is : %d\n",dequeue());
     enqueue(34);
     printf("element is : %d\n",dequeue());
     printf("element is : %d\n",dequeue());
     printf("element is : %d\n",dequeue());
     linklisttreversal(head);
     return 0;
}