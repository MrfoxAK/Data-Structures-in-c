#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
};

struct node *createlinklist(int n)
{
     struct node *head = NULL;
     struct node *temp = NULL;
     struct node *p = NULL;
     for (int i = 0; i < n; i++)
     {
          temp = (struct node *)malloc(sizeof(struct node));
          temp->next = NULL;
          printf("Enter data: ");
          scanf("%d", &temp->data);
          if (head == NULL)
          {
               head = temp;
          }
          else
          {
               p = head;
               while (p->next != NULL)
               {
                    p = p->next;
               }
               p->next = temp;
          }
     }
     return head;
}

void display(struct node *head)
{
     struct node *p = head;
     while (p != NULL)
     {
          printf("%d->", p->data);
          p = p->next;
     }
}

int count_of_nodes(struct node* head){
     int count=0;
     struct node* p=head;
     while (p!=NULL)
     {
          count++;
          p=p->next;
     }
}

void Reorder_List(struct node* head,int n){
     struct node* p=head;
     struct node* last=head->next;
     struct node* last_prev=head;
     if (n%2==0)
     {
          while (p->next!=NULL)
          {
               last=p->next;
               last_prev=p;
               while (last->next!=NULL)
               {
                    last = last->next;
                    last_prev = last_prev->next;
               }
               last->next = p->next;
               last_prev->next = NULL;
               p->next = last;
               p=p->next->next;
               if (p->next->next==NULL)
               {
                    break;
               }
          }
     }
     else
     {
          while (p->next!=NULL)
          {
               last=p->next;
               last_prev=p;
               while (last->next!=NULL)
               {
                    last = last->next;
                    last_prev = last_prev->next;
               }
               last->next = p->next;
               last_prev->next = NULL;
               p->next = last;
               p=p->next->next;
          }
     }
}

int main()
{
     int n;
     struct node *head = NULL;
     printf("Enter how many nodes: ");
     scanf("%d", &n);
     head = createlinklist(n);
     display(head);
     printf("NULL");
     Reorder_List(head,n);
     display(head);
     printf("NULL");
     return 0;
}