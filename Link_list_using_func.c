#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
};

struct node *createlinklist(int n);
void display(struct node *head);

int main()
{
     int n;
     struct node *head = NULL;
     printf("Enter how many nodes: ");
     scanf("%d", &n);
     head = createlinklist(n);
     display(head);
     printf("NULL");
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
}

// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//      int data;
//      struct node * next;
// };

// struct node * createLinkList(int n);
// void display(struct node* head);

// int main()
// {
//      int n=0;
//      struct node * head = NULL;
//      printf("How many nodes : ");
//      scanf("%d",&n);
//      head = createLinkList(n);
//      display(head);
//      return 0;
// }

// struct node * createLinkList(int n){
//      int i=0;
//      struct node * head = NULL;
//      struct node * temp = NULL;
//      struct node * p = NULL;
//      for ( i = 1; i <= n; i++)
//      {
//           // let us create individual node
//           temp = (struct node*)malloc(sizeof(struct node));
//           printf("Enter the data for node %d : ",i);
//           scanf("%d",&temp->data);
//           temp->next = NULL;

//           if (head==NULL) //if list is empty, then make temp as first node
//           {
//                head=temp;
//           }
//           else
//           {
//                p = head;
//                while (p->next!=NULL)
//                {
//                     p=p->next;
//                }
//                p->next = temp;
//           }
//      }
//      return head;
// }

// void display(struct node* head){
//      struct node * p = head;
//      while (p!=NULL)
//      {
//           printf("%d->",p->data);
//           p=p->next;
//      }
// }