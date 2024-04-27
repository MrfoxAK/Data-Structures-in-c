#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* next;
     struct node* prev;
};

void linklisttreversal(struct node *ptr)
{
     struct node* last;
     printf("\nTraversal in forward direction \n");
     while (ptr != NULL)
     {
          printf("%d ", ptr->data);
          last = ptr;
          ptr = ptr->next;
     }
     printf("\n");
     printf("\nTraversal in reverse direction \n");
     while (last!=NULL)
     {
          printf("%d ",last->data);
          last = last->prev;
     }
}

struct node* create_doubly_LL(struct node* head){
     int c = 1;
     int data;
     struct node* temp = NULL;
     struct node* new;
     while (c)
     {
          printf("Enter the Data: ");
          scanf("%d",&data);
          new=(struct node*)malloc(sizeof(struct node));
          new->data = data;
          new->next=NULL;
          new->prev=NULL;
          if (head == NULL)
          {
               head = temp = new;
          }
          else{
               temp->next = new;
               new->prev = temp;
               temp = new;
          }
          printf("Do u wanna continue? 0/1 : ");
          scanf("%d",&c);
     }
     return head;
}

int main()
{
     struct node* head = NULL;
     head = create_doubly_LL(head);
     linklisttreversal(head);
     return 0;
}