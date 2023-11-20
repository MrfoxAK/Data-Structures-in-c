#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* prev;
     struct node* next;
};

struct node* createNode(int data){
     struct node* new = (struct node*)malloc(sizeof(struct node));
     new->data = data;
     new->prev = NULL;
     new->next = NULL;
     return new;
}

void linklisttreversal(struct node *ptr)
{
     struct node* last;
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
          last = last->prev;
     }
}

struct node* create(struct node* head){
     int c = 1;
     int data;
     while (c)
     {
          printf("Enter data: ");
          scanf("%d",&data);
          struct node* temp;
          struct node* curr;
          struct node* nxt;
          curr = createNode(data);
          if (head == NULL)
          {
               head = temp = curr;
          }
          else{
               temp->next = curr;
               curr->prev = temp;
               temp = curr;
          }
          printf("Do u wanna continue ?????? 0 for exit......");
          scanf("%d",&c);
     }
     return head;
}

int main()
{
     struct node* head = NULL;
     head = create(head);
     linklisttreversal(head);
     return 0;
}