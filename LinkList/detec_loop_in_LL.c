#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
typedef struct Node
{
     int data;
     struct Node *next;
     int flag;
} Node;

void push(struct Node **head_ref, int new_data)
{
     /* allocate node */
     struct Node *new_node = (Node *)malloc(sizeof(Node));

     /* put in the data */
     new_node->data = new_data;

     new_node->flag = 0;

     /* link the old list of the new node */
     new_node->next = (*head_ref);

     /* move the head to point to the new node */
     (*head_ref) = new_node;
}

// Returns true if there is a loop in linked list
// else returns false.
int detectLoop(struct Node *h)
{
     int flag = 0;
     if (h == NULL)
     {
          return 0;
     }
     else
     {
          struct Node *s = h;
          struct Node *f = h;
          while (s && f && f->next!=NULL)
          {
               s = s->next;
               f = f->next->next;
               if (s == f)
               {
                    flag = 1;
                    return 1;
               }
          }
     }
     if (flag == 1)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

/* Driver program to test above function*/
int main()
{
     /* Start with the empty list */
     struct Node *head = NULL;

     push(&head, 20);
     push(&head, 4);
     push(&head, 15);
     push(&head, 10);

     /* Create a loop for testing */
     head->next->next->next->next = head;

     if (detectLoop(head))
          printf("Loop Found");
     else
          printf("No Loop");
     return 0;
}