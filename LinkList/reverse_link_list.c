#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
};

struct node *createlinklist(int n);
void display(struct node *head);
struct node *revserse_link_list(struct node *head);

int main()
{
     int n;
     struct node *head = NULL;
     printf("Enter how many nodes: ");
     scanf("%d", &n);
     head = createlinklist(n);
     display(head);
     printf("\n");
     head = revserse_link_list(head);
     display(head);
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

void display(struct node *head)
{
     struct node *p = head;
     while (p != NULL)
     {
          printf("%d->", p->data);
          p = p->next;
     }
     printf("NULL");
}

struct node *revserse_link_list(struct node *head)
{
     struct node *previous, *current, *next;
     previous = NULL;
     current = head;
     while (current != NULL)
     {
          next = current->next;
          current->next = previous;
          previous = current;
          current = next;
     }
     return previous;
}
