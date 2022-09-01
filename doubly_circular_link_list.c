#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* pre;
     struct node* next;
};

void display(struct node* head){
     struct node*p = head;
     do
     {
          printf("%d ",p->data);
          p=p->next;
     } while (p!=head);
     // just for checking
     printf("\n1st element is : ");
     printf("%d",p->data);
}

struct node* create_doubly_circular_linllist(struct node * head){
     int choice;
     struct node * newnode;
     struct node * temp;
     // newnode->next = newnode->pre = NULL;
     while (choice)
     {
          newnode = (struct node*)malloc(sizeof(struct node));
          printf("Enter data : ");
          scanf("%d",&newnode->data);
          if (head==NULL)
          {
               head = temp = newnode;
               temp->next = head;
               temp->pre = head;
          }
          else
          {
               temp->next = newnode;
               newnode->pre = temp;
               newnode->next = head;
               head->pre = newnode;
               temp = newnode;
          }
          printf("Enter your choice : 1 for continue , 0 for break\n");
          scanf("%d",&choice);
     }
     return head;
}

int main()
{
     struct node * head = NULL;
     head = create_doubly_circular_linllist(head);
     display(head);
     return 0;
}