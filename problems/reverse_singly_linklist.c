#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
     int data;
     struct node *next;
} node;

node * reverse_singly_linklist(node* head){
     node * cp = head;
     node * np = head;
     node * temp = NULL;
     while (cp!=NULL)
     {
          np = cp->next;
          cp->next=temp;
          temp=cp;
          cp=np;
     }
     return temp;
}

int main()
{
     node *head, *newNode, *temp;
     head = NULL;
     int choice;
     while (choice)
     {
          newNode = (node *)malloc(sizeof(node));
          printf("Enter data: ");
          scanf("%d", &newNode->data);
          newNode->next = NULL;
          if (head == NULL)
          {
               head = temp = newNode;
          }
          else
          {
               temp->next = newNode;
               temp = newNode;
          }
          printf("Do you want to continue (1/0) : ");
          scanf("%d", &choice);
     }

     temp = head;
     while (temp != NULL)
     {
          printf("%d -> ", temp->data);
          temp = temp->next;
     }
     head = reverse_singly_linklist(head);
     printf("\n");
     temp = head;
     while (temp != NULL)
     {
          printf("%d -> ", temp->data);
          temp = temp->next;
     }
     return 0;
}