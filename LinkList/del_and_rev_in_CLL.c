#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* next;
};

void traCLL(struct node* head){
     struct node* temp = head;
     while (temp->next != head)
     {
          printf("%d -> ", temp->data);
          temp = temp->next;
     }
     printf("%d",temp->data);
}

struct node* createCLL(struct node* head){
     struct node* temp = NULL;
     int data;
     int c;
     while (c)
     {
          printf("Enter the Data : ");
          scanf("%d",&data);
          struct node* n = (struct node*)malloc(sizeof(struct node));
          n->data = data;
          n->next = NULL;
          if (head == NULL)
          {
               head = temp = n;
          }
          else
          {
               temp->next = n;
               temp = n;
          }
          printf("Do you want to continue (1/0) : ");
          scanf("%d", &c);
     }
     temp->next = head;
     return head;
}

struct node* deleteNode(struct node* head, int key){
     struct node* temp = head;
     while (temp->next->data != key)
     {
          temp = temp->next;
     }
     temp->next = temp->next->next;
     return head;
}

struct node* reverse(struct node* head){
     struct node* temp = head;
     struct node* prev = NULL;
     struct node* curr = head;
     struct node* nxt = head;
     do
     {
          nxt = curr->next;
          curr->next = prev;
          prev = curr;
          curr = nxt;
     } while (curr!=head);
     head->next = prev;
     return head = prev;
}

int main()
{
     struct node* head = NULL;
     head = createCLL(head);
     traCLL(head);
     printf("\n");
     deleteNode(head, 8);
     printf("\n");
     traCLL(head);
     head = reverse(head);
     printf("\n");
     traCLL(head);
     return 0;
}