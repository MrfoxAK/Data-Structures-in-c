#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* next;
};

struct node* create_LL(struct node* head){
     struct node* new;
     struct node* temp;
     int c = 1;
     int data;
     while (c)
     {
          printf("Enter the data : ");
          new = (struct node*)malloc(sizeof(struct node));
          scanf("%d",&new->data);
          new->next = NULL;
          if (head == NULL)
          {
               head = temp = new;
          }
          else{
               temp->next = new;
               temp = new;
          }
          printf("Do u want to continue? 1/0 : ");
          scanf("%d",&c);
     }
     return head;
}

void display(struct node* head){
     struct  node* temp = head;
     while (temp!=NULL)
     {
          printf("%d->",temp->data);
          temp = temp->next;
     }
}

struct node* remove_duplicate(struct node* head){
     struct node* temp = head;
     struct node* nxt;
     struct node* prev;
     int i = 0;
     while (temp->next!=NULL)
     {
          nxt = temp->next;
          if(temp->data == nxt->data){
               temp->next = nxt->next;
          }
          else{
               temp = temp->next;
          }
     }
     return head;
}

int main()
{
     struct node* head = NULL;
     head = create_LL(head);
     display(head);
     printf("\nAfter removing duplicates.....\n");
     head = remove_duplicate(head);
     display(head);
     return 0;
}