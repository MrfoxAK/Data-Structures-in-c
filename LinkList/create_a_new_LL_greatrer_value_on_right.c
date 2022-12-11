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
          printf("Enter data for %d node : ",i);
          scanf("%d",&temp->data);
          if (head==NULL)
          {
               head=temp;
               temp->next=NULL;
          }
          else
          {
               p=head;
               while (p->next!=NULL)
               {
                    p=p->next;
               }
               p->next=temp;
               temp->next=NULL;
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

struct Node* del_nodes_values_greater_at_right(struct Node* head){
     struct Node* temp = head;
     struct Node* newHead = NULL;
     struct Node* newHeadtemp = NULL;
     while (temp->next!=NULL)
     {
          if (temp->data < temp->next->data)
          {
               struct Node* tn = temp->next;
               if (newHead==NULL)
               {
                    newHead = newHeadtemp = tn;
               }
               else{
                    newHeadtemp->next = tn;
                    newHeadtemp = tn;
               }
               temp->next = tn->next;
               // free(tn);
          }
          else{
               temp = temp->next;
          }
     }
     return newHead;
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
     struct Node* newHead = del_nodes_values_greater_at_right(head);
     display(head);
     printf("\n");
     display(newHead);
     return 0;
}