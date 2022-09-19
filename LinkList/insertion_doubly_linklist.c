#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
     struct node *pre;
};

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
          last = last->pre;
     }
}

struct node *createDoubly_linklist(struct node *head, int n)
{
     struct node *temp;
     struct node *p;
     for (int i = 0; i < n; i++)
     {
          temp = (struct node *)malloc(sizeof(struct node));
          printf("Enter data: ");
          scanf("%d", &temp->data);
          temp->pre = NULL;
          temp->next = NULL;
          if (head == NULL)
          {
               head = p = temp;
          }
          else
          {
               p->next = temp;
               temp->pre = p;
               p=temp;
          }
     }
     return head;
}

struct node * insertAt1st(struct node* head,int data){
     struct node* newNode;
     newNode=(struct node*)malloc(sizeof(struct node));
     newNode->data = data;
     newNode->pre=NULL;
     newNode->next=head;
     head->pre=newNode;
     head = newNode;
     return head;
}

struct node * insertAtlast(struct node* head,int data){
     struct node* newNode;
     struct node* p=head;
     newNode=(struct node*)malloc(sizeof(struct node));
     newNode->data = data;
     while (p->next!=NULL)
     {
          p=p->next;
     }
     p->next=newNode;
     newNode->pre=p;
     newNode->next=NULL;
     return head;
}

struct node * insertAtpos(struct node* head,int data,int pos){
     struct node* newNode;
     struct node* p=head;
     struct node* p1=head->next;
     newNode=(struct node*)malloc(sizeof(struct node));
     newNode->data = data;
     int i=0;
     while (i!=pos-2)
     {
          p1=p1->next;
          p=p->next;
          i++;
     }
     newNode->next = p->next;
     p->next=newNode;
     newNode->pre=p;
     p1->pre=newNode;
     // newNode->next->pre = newNode;
     return head;
}

int main()
{
     int n;
     struct node *head = NULL;
     printf("How many nodes u want: ");
     scanf("%d", &n);
     head = createDoubly_linklist(head, n);
     linklisttreversal(head);
     printf("After inserting 1st position : \n");
     // head = insertAt1st(head,8);
     // head = insertAt1st(head,18);
     // head = insertAtlast(head,184);
     head = insertAtpos(head,184,2);
     linklisttreversal(head);
     return 0;
}