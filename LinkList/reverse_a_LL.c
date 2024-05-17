#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
     int data;
     struct node *next;
} node;

node * rev_linklist(node * head){
     node* temp = head;
     node* nxt = head;
     node* prev = NULL;
     while (nxt!=NULL)
     {
          nxt = temp->next;
          temp->next = prev;
          prev = temp;
          temp = nxt;
     }
     head = prev;
     return head;
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
          printf("%d-> ", temp->data);
          temp = temp->next;
     }
     head = rev_linklist(head);
     temp = head;
     printf("\nrev is : \n");
     while (temp != NULL)
     {
          printf("%d-> ", temp->data);
          temp = temp->next;
     }
     return 0;
}