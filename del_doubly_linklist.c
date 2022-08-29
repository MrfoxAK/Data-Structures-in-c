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

struct node * deleteAt1st(struct node* head){
     // struct node* p = NULL;
     struct node* ptr = NULL;
     // p = p->next;
     // p->pre = ptr->pre;
     // head = p;
     // free(ptr);
     if (head==NULL)
     {
          printf("LinkList is empty....\n");
     }
     else
     {
          ptr=head;
          head = head->next;
          head->pre=NULL;
          free(ptr);
     }
     return head;
}

struct node * deleteAtlast(struct node* head){
     struct node* ptr=NULL;
     struct node* p=NULL;
     if (head==NULL)
     {
          printf("LinkList is empty....\n");
     }
     else
     {
          p=head;
          ptr=head->next;
          while (ptr->next!=NULL)
          {
               ptr=ptr->next;
               p=p->next;
          }
          p->next = NULL;
          free(ptr);
     }
     
     return head;
}

struct node * deleteAtpos(struct node* head,int pos){
     // struct node* p=head;
     struct node* ptr=head;
     // int i=0;
     // while (i!=pos-2)
     // {
     //      ptr=ptr->next;
     //      p=p->next;
     //      i++;
     // }
     // p->next=ptr->next;
     // ptr->next->pre=ptr->pre;
     // free(ptr);
     int i=0;
     while (i!=pos-1)
     {
          ptr=ptr->next;
          // p=p->next;
          i++;
     }
     ptr->next->pre=ptr->pre;
     ptr->pre->next = ptr->next;
     free(ptr);
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
     head = deleteAtpos(head,2);
     linklisttreversal(head);
     return 0;
}