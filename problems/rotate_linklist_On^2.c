// Rotate a Linked List n times
// brute force method
// in O(n^2)

#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
};

struct node *createlinklist(int n);
struct node *rotate_linklist(struct node* head,int x);
void display(struct node *head);

int main()
{
     int n,r;
     struct node *head = NULL;
     printf("Enter how many nodes: ");
     scanf("%d", &n);
     head = createlinklist(n);
     display(head);
     printf("NULL");
     printf("\nEnter How many time rotate: ");
     scanf("%d",&r);
     head = rotate_linklist(head,r);
     printf("\n");
     display(head);
     printf("NULL");
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

struct node *rotate_linklist(struct node* head,int x){
     for (int i = 0; i < x; i++)
     {
          struct node * p = head;
          struct node * ptr = head;
          head=head->next;
          while (p->next!=NULL)
          {
               p=p->next;
          }
          p->next = ptr;
          ptr->next=NULL;
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