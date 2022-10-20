#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
     struct node *pre;
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
          last = last->pre;
     }
}

struct node *createDoubly_linklist(struct node *head, int n)
{
     struct node* new;
     struct node* temp;
     for (int i = 0; i < n; i++)
     {
          new=(struct node*)malloc(sizeof(struct node));
          new->next=NULL;
          new->pre=NULL;
          printf("Enter data: ");
          scanf("%d",&new->data);
          if (head==NULL)
          {
               head = temp =  new;
          }
          else
          {
               temp->next=new;
               new->pre=temp;
               temp=new;
          }
     }
     return head;
}

int main()
{
     int n;
     struct node *head = NULL;
     printf("How many nodes u want: ");
     scanf("%d", &n);
     head = createDoubly_linklist(head, n);
     linklisttreversal(head);
     return 0;
}

