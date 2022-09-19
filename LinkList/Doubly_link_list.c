#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node *pre;
     struct Node *next;
};

void linklisttreversal(struct Node *ptr)
{
     struct Node* last;
     printf("\nTraversal in forward direction \n");
     while (ptr != NULL)
     {
          printf("%d ", ptr->data);
          last = ptr;
          ptr = ptr->next;
     }
     printf("\n");
     printf("\nTraversal in reverse direction \n");
     while (last!=NULL)
     {
          printf("%d ",last->data);
          last = last->pre;
     }
     
}

int main()
{
     struct Node *head;
     struct Node *sec;
     struct Node *third;
     struct Node *fourth;

     head = (struct Node *)malloc(sizeof(struct Node));
     sec = (struct Node *)malloc(sizeof(struct Node));
     third = (struct Node *)malloc(sizeof(struct Node));
     fourth = (struct Node *)malloc(sizeof(struct Node));

     head->pre = NULL;
     head->data = 14;
     head->next = sec;

     sec->pre = head;
     sec->data = 151;
     sec->next = third;

     third->pre = sec;
     third->data = 66;
     third->next = fourth;

     fourth->pre = third;
     fourth->data = 24;
     fourth->next = NULL;

     linklisttreversal(head);
     return 0;
}