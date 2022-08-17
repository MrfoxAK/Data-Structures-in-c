#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node* next;
};

struct Node* createLinklist(int n){
     struct Node* head=NULL;
     struct Node* temp=NULL;
     struct Node* p=NULL;
     for (int i = 0; i < n; i++)
     {
          temp = (struct Node*)malloc(sizeof(struct Node));
          temp->next=NULL;
          printf("Enter data for %d node : ",i);
          scanf("%d",&temp->data);
          if (head==NULL)
          {
               head=temp;
          }
          else
          {
               p=head;
               while (p->next!=NULL)
               {
                    p=p->next;
               }
               p->next=temp;
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


int main()
{
     int n;
     struct Node* head=NULL;
     printf("Enter how many nodes u want : ");
     scanf("%d",&n);
     head = createLinklist(n);
     display(head);
     printf("NULL\n");
     return 0;
}