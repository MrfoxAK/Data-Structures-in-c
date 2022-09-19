#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
};

struct node * createlist()
{
     int user;
     struct node *head = NULL;
     struct node *p = NULL;
     struct node *newnode = NULL;
     while (1)
     {
          label:
          newnode = (struct node *)malloc(sizeof(struct node));
          printf("Enter data : ");
          scanf("%d", &newnode->data);
          newnode->next = NULL;
          if (head == NULL)
          {
               head = newnode;
          }
          else
          {
               p = head;
               while (p->next != NULL)
               {
                    p = p->next;
               }
               p->next = newnode;
          }
          printf("Do you want to continue?(1/0) : ");
          scanf("%d",&user);
          if (user==0)
          {
               break;
          }
     }
     return head;
}

void display(struct node * head){
     struct node*p1=head;
     while (p1!=NULL)
     {
          printf("%d->",p1->data);
          p1=p1->next;
     }
     printf("NULL");
}

int main()
{
     struct node *head = NULL;
     head = createlist();
     printf("The linklist is : ");
     display(head);
     return 0;
}