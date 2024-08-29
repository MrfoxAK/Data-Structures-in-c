#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* next;
};

void display(struct node *head)
{
     struct node *p = head;
     while (p != NULL)
     {
          printf("%d->", p->data);
          p = p->next;
     }
}

struct node* insert(struct node* head, int data){
     struct node* temp = head;
     struct node* new = (struct node*)malloc(sizeof(struct node));
     new->data = data;
     new->next = NULL;
     if (head == NULL)
     {
          head = new;
     }
     else{
          while (temp->next!=NULL)
          {
               temp = temp->next;
          }
          temp->next = new;
     }
     return head;
}

struct node* createLoop(struct node* head, int pos){
     struct node* temp = head;
     struct node* p = head;
     int i = 1;
     while (i<pos)
     {
          p = p->next;
          i++;
     }
     while (temp->next!=NULL)
     {
          temp = temp->next;
     }
     temp->next = p;
     return head;
}

int loopLength(struct node* head){
     struct node* slow = head;
     struct node* fast = head;
     int count = 0;
     while (slow != NULL && fast != NULL)
     {
          slow = slow->next;
          fast = fast->next->next;
          count++;
          if (slow->data == fast->data)
          {
               break;
          }
     }
     return count;
}

int main()
{
     struct node* head = NULL;
     head = insert(head,25);
     head = insert(head,14);
     head = insert(head,19);
     head = insert(head,33);
     head = insert(head,10);
     head = insert(head,21);
     head = insert(head,39);
     head = insert(head,90);
     head = insert(head,58);
     head = insert(head,45);
     // display(head);
     head = createLoop(head,4);
     // display(head);
     printf("The Length of the Loop is = %d\n",loopLength(head));
     return 0;
}