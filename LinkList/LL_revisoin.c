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

struct node* create(struct node* head){
     int c=1,data;
     while (c)
     {
          printf("Enter data: ");
          scanf("%d",&data);
          struct node* temp;
          struct node* new = (struct node*)malloc(sizeof(struct node));
          new->data=data;
          new->next=NULL;
          if (head==NULL)
          {
               head = temp = new;
          }
          else{
               temp->next = new;
               temp=new;
          }
          printf("Do u want to continue? 1/0: ");
          scanf("%d",&c);
     }
     return head;
}

struct node* rev_LL(struct node* head){
     struct node* temp=head;
     struct node* nxt=head;
     struct node* prev=NULL;
     while (nxt)
     {
          nxt = nxt->next;
          temp->next = prev;
          prev = temp;
          temp = nxt;  
     }
     return prev;
}

int main()
{
     struct node* head=NULL;
     head = create(head);
     display(head);
     printf("Now rev the LL......\n");
     head = rev_LL(head);
     display(head);
     return 0;
}