#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node* next;
}*head;

void display(struct Node* head){
     struct Node * temp;
     if (head==NULL)
     {
          printf("Linklist is empty");
     }
     else
     {
          temp=head;
          while (temp->next!=head)
          {
               printf("%d->",temp->data);
               temp=temp->next;
          }
          printf("%d",temp->data);
          printf("->NULL\n");
     }
}

struct Node* CreateLinklist(){
     int choice;
     struct Node* newNode;
     struct Node* p=NULL;
     struct Node* temp=NULL;
     head=NULL;
     while (choice)
     {
          newNode=(struct Node*)malloc(sizeof(struct Node));
          printf("Enter data: ");
          scanf("%d",&newNode->data);
          newNode->next=NULL;
          if (head==NULL)
          {
               head=temp=newNode;
          }
          else
          {
               // p=head;
               // while (p->next!=NULL)
               // {
               //      p=p->next;
               // }
               // p->next=newNode;
               temp->next=newNode;
               temp=newNode;
          }
          temp->next=head;
          printf("1 for continue, 0 for exit.\n");
          scanf("%d",&choice);
     }
     return head;
}

int main()
{
     head=CreateLinklist();
     display(head);
     return 0;
}