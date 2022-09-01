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


// in O(n^2)
void pairsum(struct Node *head,int target){
     struct Node *p = head;
     struct Node *ptr = NULL;
     int sum=0;
     while (p!=NULL){
          ptr=p->next;
          while (ptr!=NULL)
          {
               sum=0;
               sum+=ptr->data+p->data;
               if (sum==target)
               {
                    printf("(%d,%d)",p->data,ptr->data);
               }
               ptr=ptr->next;
          }
          p=p->next;
     }
}

int main()
{
     struct Node *head;
     struct Node *sec;
     struct Node *third;
     struct Node *fourth;
     struct Node *five;
     struct Node *six;
     struct Node *seven;

     head = (struct Node *)malloc(sizeof(struct Node));
     sec = (struct Node *)malloc(sizeof(struct Node));
     third = (struct Node *)malloc(sizeof(struct Node));
     fourth = (struct Node *)malloc(sizeof(struct Node));
     five = (struct Node *)malloc(sizeof(struct Node));
     six = (struct Node *)malloc(sizeof(struct Node));
     seven = (struct Node *)malloc(sizeof(struct Node));

     head->pre = NULL;
     head->data = 1;
     head->next = sec;

     sec->pre = head;
     sec->data = 2;
     sec->next = third;

     third->pre = sec;
     third->data = 4;
     third->next = fourth;

     fourth->pre = third;
     fourth->data = 5;
     fourth->next = five;

     five->pre = fourth;
     five->data = 6;
     five->next = six;

     six->pre = five;
     six->data = 8;
     six->next = seven;

     seven->pre = six;
     seven->data = 9;
     seven->next = NULL;

     // linklisttreversal(head);
     pairsum(head,7);
     return 0;
}