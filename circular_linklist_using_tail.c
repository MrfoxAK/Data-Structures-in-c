#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
};

void display(struct node *tail)
{
     struct node *p = tail;
     do
     {
          p=p->next;
          printf("%d->",p->data);
     } while (p!=tail);
}

struct node *create_Circular_linklist(struct node *tail)
{
     int choice;
     struct node *newnode;
     while (choice)
     {
          newnode = (struct node *)malloc(sizeof(struct node));
          printf("Enter data : ");
          scanf("%d", &newnode->data);
          if (tail == NULL)
          {
               tail = newnode;
               tail->next = newnode;
          }
          else
          {
               newnode->next = tail->next;
               tail->next = newnode;
               tail = newnode;
          }
          printf("Enter 1 for continue , 0 for exit\n");
          scanf("%d", &choice);
     }
     return tail;
}

int main()
{
     struct node *tail = NULL;
     tail = create_Circular_linklist(tail);
     display(tail);
     return 0;
}







// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//      int data;
//      struct node * next;
// };

// void display(struct node * head){
//      struct node * p = head;
//      do
//      {
//           printf("%d->",p->data);
//           p=p->next;
//      } while (p!=head);
//      // for checking purpose
//      // printf("Data is : %d",p->data);
// }

// struct node * create_Circular_linklist(struct node * head){
//      int choice;
//      struct node* newnode;
//      struct node* temp;
//      while (choice)
//      {
//           newnode = (struct node*)malloc(sizeof(struct node));
//           printf("Enter data : ");
//           scanf("%d",&newnode->data);
//           if (head==NULL)
//           {
//                head=temp=newnode;
//           }
//           else{
//                temp->next = newnode;
//                temp=newnode;
//           }
//           temp->next = head;
//           printf("Enter 1 for continue , 0 for exit\n");
//           scanf("%d",&choice);
//      }
//      return head;
// }

// int main()
// {
//      struct node * head = NULL;
//      head = create_Circular_linklist(head);
//      display(head);
//      return 0;
// }