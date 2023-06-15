#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* next;
};

struct node* createNode(int data){
     struct node* new = (struct node*)malloc(sizeof(struct node));
     new->data = data;
     new->next = NULL;
     return new;
}

void display(struct node* head){
     struct node* temp = head;
     while (temp != NULL)
     {
          printf("%d -> ", temp->data);
          temp = temp->next;
     }
}

struct node* create(struct node* head){
     int c = 1;
     int data;
     struct node* temp = NULL;
     while (c)
     {
          printf("Enter data: ");
          scanf("%d",&data);
          struct node* new = createNode(data);
          if(head == NULL){
               head = temp = new;
          }
          else{
               temp->next = new;
               temp = new;
          }
          printf("Do u want to continue? (1/0): ");
          scanf("%d",&c);
     }
     return head;
}

int main()
{
     struct node* head = NULL;
     head = create(head);
     display(head);
     return 0;
}