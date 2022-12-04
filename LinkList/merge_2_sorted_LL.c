#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
};

struct node *createlinklist(int n);
struct node *merge_two_linklist(struct node *head1, struct node *head2);
void display(struct node *head);

int main()
{
     int n1, n2;
     struct node *head1 = NULL;
     struct node *head2 = NULL;
     struct node *head3 = NULL;
     printf("Enter how many nodes: ");
     scanf("%d", &n1);
     head1 = createlinklist(n1);
     display(head1);
     printf("Enter how many nodes: ");
     scanf("%d", &n2);
     printf("\n");
     head2 = createlinklist(n2);
     display(head2);
     printf("\n");
     head1 = merge_two_linklist(head1, head2);
     display(head1);
     // display(head2);
     return 0;
}

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
     printf("NULL\n");
}

// merge 
struct node *merge_two_linklist(struct node *head1, struct node *head2)
{
     struct node *p = head1;
     struct node *q = head2;
     struct node *temp = head2;
     struct node *newhead = NULL;
     while (p && q)
     {
          if (newhead==NULL)
          {
               if (p->data < q->data)
               {
                    newhead = temp =p;
                    p=p->next;
               }
               else{
                    newhead = temp = q;
                    q = q->next;
               }
          }
          else
          {
               if (p->data < q->data)
               {
                    temp->next = p;
                    temp = p;
                    p = p->next;
               }
               else
               {
                    temp->next = q;
                    temp = q;
                    q = q->next;
               }
          }
     }
     while (p)
     {
          temp->next = p;
          temp = p;
          p = p->next;
     }
     while (q)
     {
          temp->next = q;
          temp = q;
          q = q->next;
     }
     return newhead;
}