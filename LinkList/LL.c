#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* next;
};

void display(struct node* head){
     struct node*ptr=head;
     while (ptr!=NULL)
     {
          printf("%d->",ptr->data);
          ptr=ptr->next;
     }
     printf("NULL\n");
}

struct node* create_LL(struct node * head){
     struct node * temp=NULL;
     struct node * new;
     int c=1;
     while (c)
     {
          new = (struct node*)malloc(sizeof(struct node));
          new->next=NULL;
          printf("Enter data: ");
          scanf("%d",&new->data);
          if (head==NULL)
          {
               head = temp = new;
          }
          else{
               temp->next = new;
               temp = new;
          }
          printf("Enter 0 for break & 1 for continue: ");
          scanf("%d",&c);
     }
     return head;
}

int main()
{
     struct node * head=NULL;
     head = create_LL(head);
     display(head);
     return 0;
}