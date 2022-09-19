#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
     int data;
     struct node *next;
} node;

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
     return 0;
}