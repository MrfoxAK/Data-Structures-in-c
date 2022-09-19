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

int main()
{
     int n;
     struct node *head = NULL;
     printf("How many nodes u want: ");
     scanf("%d", &n);
     head = createDoubly_linklist(head, n);
     linklisttreversal(head);
     return 0;
}





// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//      int data;
//      struct node *next;
//      struct node *pre;
// };

// void linklisttreversal(struct node *ptr)
// {
//      struct node* last;
//      printf("\nTraversal in forward direction \n");
//      while (ptr != NULL)
//      {
//           printf("%d ", ptr->data);
//           last = ptr;
//           ptr = ptr->next;
//      }
//      printf("\n");
//      printf("\nTraversal in reverse direction \n");
//      while (last!=NULL)
//      {
//           printf("%d ",last->data);
//           last = last->pre;
//      }
     
// }

// struct node *createDoubly_linklist(struct node *head, int n)
// {
//      struct node *temp;
//      struct node *p;
//      for (int i = 0; i < n; i++)
//      {
//           temp = (struct node *)malloc(sizeof(struct node));
//           printf("Enter data: ");
//           scanf("%d", &temp->data);
//           temp->pre = NULL;
//           temp->next = NULL;
//           if (head == NULL)
//           {
//                head = temp;
//           }
//           else
//           {
//                p = head;
//                while (p->next != NULL)
//                {
//                     p = p->next;
//                }
//                p->next = temp;
//                temp->pre = p;
//           }
//      }
//      return head;
// }

// int main()
// {
//      int n;
//      struct node *head = NULL;
//      printf("How many nodes u want: ");
//      scanf("%d", &n);
//      head = createDoubly_linklist(head, n);
//      linklisttreversal(head);
//      return 0;
// }