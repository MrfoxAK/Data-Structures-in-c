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

struct node *Sort_a_LL(struct node *head)
{
     struct node* curr = head,*nxt = head;
     int temp;
     if(head == NULL) {
          return NULL;  
     }
     else{
          while (curr)
          {
               nxt = curr->next;
               while (nxt)
               {
                    if (curr->data > nxt->data)
                    {
                         temp = curr->data;
                         curr->data = nxt->data;
                         nxt->data = temp;
                    }
                    nxt=nxt->next;
               }
               curr = curr->next;
          }
     }
     return head;
}

struct node *Sort_of_2_LL(struct node *head1, struct node *head2)
{
     int flag;
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
               struct node* s = head2;
               flag=0;
               while (s)
               {
                    if (s->data==t2->data)
                    {
                         flag=1;
                    }
                    s=s->next;
               }
               if (flag==0)
               {
                    temp->next = t2;
               }
               temp = t2;
               t2 = t2->next;
          }
          else{
               struct node* r = head1;
               flag=0;
               while (r)
               {
                    if (r->data==t1->data)
                    {
                         flag=1;
                    }
                    r=r->next;
               }
               if (flag==0)
               {
                    temp->next= t1;
               }
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
     head1 = create_LL(head1);
     display(head1);
     head1 = Sort_a_LL(head1);
     display(head1);
     struct node *head2 = NULL;
     head2 = create_LL(head2);
     display(head2);
     head2 = Sort_a_LL(head2);
     display(head2);
     struct node * new_head = NULL;
     new_head = Sort_of_2_LL(head1,head2);
     display(new_head);
     return 0;
}