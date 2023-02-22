#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
};

void display(struct node *head)
{
     struct node *ptr = head;
     while (ptr != NULL)
     {
          printf("%d->", ptr->data);
          ptr = ptr->next;
     }
     printf("NULL\n");
}

struct node *create_LL(struct node *head)
{
     struct node *temp = NULL;
     struct node *new;
     int c = 1;
     while (c)
     {
          new = (struct node *)malloc(sizeof(struct node));
          new->next = NULL;
          printf("Enter data: ");
          scanf("%d", &new->data);
          if (head == NULL)
          {
               head = temp = new;
          }
          else
          {
               temp->next = new;
               temp = new;
          }
          printf("Enter 0 for break & 1 for continue: ");
          scanf("%d", &c);
     }
     return head;
}

struct node *Sort_of_2_LL(struct node *head1, struct node *head2)
{
     struct node *t1 = head1;
     struct node *t2 = head2;
     struct node *new_head = NULL;
     struct node *temp = NULL;
     if (t1->data < t2->data)
     {
          new_head = t1;
          temp = t1;
          t1 = t1->next;
     }
     else
     {
          new_head = t2;
          temp = t2;
          t2 = t2->next;
     }
     while (t1 && t2)
     {
          if (t2->data < t1->data)
          {
               temp->next = t2;
               temp = t2;
               t2 = t2->next;
          }
          else{
               temp->next= t1;
               temp = t1;
               t1 = t1->next;
          }
     }
     if (t1==NULL)
     {
          temp->next=t2;
     }
     else{
          temp->next=t1;
     }
     return new_head;
}

int main()
{
     struct node *head1 = NULL;
     struct node *head2 = NULL;
     struct node *new_head = NULL;
     head1 = create_LL(head1);
     head2 = create_LL(head2);
     display(head1);
     display(head2);
     new_head = Sort_of_2_LL(head1, head2);
     display(new_head);
     return 0;
}