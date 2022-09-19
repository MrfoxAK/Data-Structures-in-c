#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node *next;
};

struct Node *createLinklist(int n)
{
     struct Node *head = NULL;
     struct Node *temp = NULL;
     struct Node *p = NULL;
     for (int i = 0; i < n; i++)
     {
          temp = (struct Node *)malloc(sizeof(struct Node));
          printf("Enter data for %d node : ", i);
          scanf("%d", &temp->data);
          if (head == NULL)
          {
               head = temp;
               temp->next = NULL;
          }
          else
          {
               p = head;
               while (p->next != NULL)
               {
                    p = p->next;
               }
               p->next = temp;
               temp->next = NULL;
          }
     }
     return head;
}

void display(struct Node *head)
{
     struct Node *p = head;
     while (p != NULL)
     {
          printf("%d->", p->data);
          p = p->next;
     }
}

struct Node *sort(struct Node *head)
{
     int count0 = 0, count1 = 0, count2 = 0;
     struct Node *count = head;
     while (count != NULL)
     {
          if (count->data == 0)
               count0 += 1;
          else if (count->data == 1)
               count1 += 1;
          else if (count->data == 2)
               count2 += 1;
          count = count->next;
     }
     struct Node *newnode;
     struct Node *temp;
     struct Node *newhead=NULL;
     while (count0)
     {
          newnode=(struct Node *)malloc(sizeof(struct Node));
          newnode->data=0;
          // newnode->next=NULL;
          if (newhead==NULL)
          {
               newhead=temp=newnode;
          }
          else
          {
               temp->next=newnode;
               temp=newnode;
          }
          count0--;
     }
     while (count1)
     {
          newnode=(struct Node *)malloc(sizeof(struct Node));
          newnode->data=1;
          temp->next=newnode;
          temp=newnode;
          count1--;
     }
     // temp->next=NULL;
     while (count2)
     {
          newnode=(struct Node *)malloc(sizeof(struct Node));
          newnode->data=2;
          temp->next=newnode;
          temp=newnode;
          count2--;
     }
     temp->next=NULL;
     return newhead;
}

int main()
{
     int n;
     struct Node *head = NULL;
     printf("Enter how many nodes u want : ");
     scanf("%d", &n);
     head = createLinklist(n);
     display(head);
     printf("NULL\n");
     head=sort(head);
     display(head);
     printf("NULL\n");
     return 0;
}