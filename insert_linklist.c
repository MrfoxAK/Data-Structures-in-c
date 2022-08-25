#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
};

struct node *createlinklist(int n);
void display(struct node *head);
struct node * insertAt1st(struct node *head,int data);
struct node * insertAtlast(struct node *head,int data);
struct node *insertAtIndex(struct node *head, int data, int index);

int main()
{
     int n;
     struct node *head = NULL;
     printf("Enter how many nodes: ");
     scanf("%d", &n);
     head = createlinklist(n);
     display(head);
     head=insertAt1st(head,5);
     head=insertAtlast(head,65);
     head=insertAtIndex(head,25,2);
     printf("\n");
     display(head);
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

struct node * insertAt1st(struct node *head,int data){
     struct node* insertenNode = NULL;
     insertenNode = (struct node *)malloc(sizeof(struct node));
     insertenNode->data=data;
     insertenNode->next=head;
     head=insertenNode;
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
     printf("NULL");
}

struct node * insertAtlast(struct node *head,int data){
     struct node* insertenNode = NULL;
     insertenNode = (struct node *)malloc(sizeof(struct node));
     insertenNode->data=data;
     struct node *p = head;
     while (p->next != NULL)
     {
          p = p->next;
     }
     p->next=insertenNode;
     insertenNode->next=NULL;
     return head;
}

struct node *insertAtIndex(struct node *head, int data, int index)
{
    struct node *NewNode = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    NewNode->data = data;
    NewNode->next = p->next;
    p->next = NewNode;
    return head;
}