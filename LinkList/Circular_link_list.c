#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node *next;
};

// using do while
void linklisttreversal(struct Node *head)
{
     struct Node *ptr = head;
     do
     {
          printf("Element is : %d\n", ptr->data);
          ptr = ptr->next;
     } while (ptr!=head);
}

// without do while
// void linklisttreversal(struct Node * head){
//      struct Node * ptr = head;
//      printf("Element is : %d\n",ptr->data);
//      ptr = ptr->next;
//     while (ptr!=head)
//     {
//          printf("Element is : %d\n",ptr->data);
//          ptr = ptr->next;
//     }
// }
 
struct Node* InsertatStart(struct Node * head , int data){
     struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
     ptr->data = data;

     struct Node* p = head->next;
     while (p->next != head)
     {
          p = p->next;
     }
     // At this point p points to the last node of this circular linked list

     p->next = ptr;
     ptr->next = head;
     head = ptr;
     return head;
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

     head->data = 4;
     head->next = sec;

     sec->data = 3;
     sec->next = third;

     third->data = 6;
     third->next = fourth;

     fourth->data = 1;
     fourth->next = head;
     printf("At first............\n");
     linklisttreversal(head);
     head = InsertatStart(head, 177);
     head = InsertatStart(head, 17);
     printf("After insert at first............\n");
     linklisttreversal(head);

     return 0;
}
