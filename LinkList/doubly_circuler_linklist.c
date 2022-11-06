#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* next;
     struct node* prev;
};

void traversal(struct node* head){
     struct node*p = head;
     do
     {
          printf("%d->",p->data);
          p=p->next;
     } while (p!=head);
     // just for checking
     printf("\n1st element is : ");
     printf("%d",p->data);
}

struct node * create_doubly_circuler_LL(struct node* head){
     int c=1;
     struct node* temp;
     while (c)
     {
          struct node* new;
          new = (struct node*)malloc(sizeof(struct node));
          new->next=NULL;
          new->prev=NULL;
          printf("Enter data: ");
          scanf("%d",&new->data);
          if (head==NULL)
          {
               head = temp = new;
               temp->next = head;
               temp->prev = head;
          }
          else
          {
               temp->next = new;
               new->prev = temp;
               new->next = head;
               head->prev = new;
               temp = new;
          }
          printf("Do u want to continue 1/0 ?");
          scanf("%d",&c);
     }
     return head;
}


int main()
{
     struct node* head = NULL;
     head = create_doubly_circuler_LL(head);
     traversal(head);
     return 0;
}