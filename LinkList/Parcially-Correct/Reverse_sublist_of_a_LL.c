// ---------- This is Perfect algorithm ----------
// ---------- except the corner caseses ----------
// ---------- like 1st and last element ----------

#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
};

struct node *createlinklist(int n);
void display(struct node *head);
struct node *rev_sublist(struct node *head, int m, int n);
struct node *reverse(struct node *newHead);

int main()
{
     int N;
     struct node *head = NULL;
     printf("Enter how many nodes: ");
     scanf("%d", &N);
     head = createlinklist(N);
     display(head);
     printf("NULL\n");
     int m, n;
     printf("Enter m: ");
     scanf("%d", &m);
     printf("Enter n: ");
     scanf("%d", &n);
     rev_sublist(head, m, n);
     display(head);
     printf("NULL\n");
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

struct node *rev_sublist(struct node *head, int m, int n)
{
     struct node *ptr_start = head;
     struct node *ptr_start_prev = head;
     struct node *ptr_end = head;
     struct node *ptr_end_next = head;
     int i = 1;
     while (i != m)
     {
          ptr_start = ptr_start->next;
          i++;
     }
     i = 1;
     while (i != n)
     {
          ptr_end = ptr_end->next;
          i++;
     }
     // printf("\nThe ptr_start is now : %d\n",ptr_start->data);
     // printf("\nThe ptr_end is now : %d\n",ptr_end->data);
     if (m == 1)
     {
          ptr_start_prev = head;
     }
     else
     {
          while (ptr_start_prev->next != ptr_start)
          {
               ptr_start_prev = ptr_start_prev->next;
          }
     }
     ptr_end_next = ptr_end->next;
     printf("\nThe ptr_start_prev is now : %d\n", ptr_start_prev->data);
     printf("\nThe ptr_end_next is now : %d\n", ptr_end_next->data);
     struct node *newHead = NULL;
     struct node *temp = ptr_start;
     while (temp->next != ptr_end_next)
     {
          // printf("%d ",temp->data);
          temp = temp->next;
     }
     temp->next = NULL;
     newHead = ptr_start;
     newHead = reverse(newHead);
     ptr_start_prev->next = newHead;
     struct node *temp1 = head;
     while (temp1->next != NULL)
     {
          temp1 = temp1->next;
     }
     temp1->next = ptr_end_next;
     return head;
}

struct node *reverse(struct node *newHead)
{
     struct node *ptr = NULL;
     struct node *curr = newHead;
     struct node *next = newHead;
     while (curr != NULL)
     {
          next = curr->next;
          curr->next = ptr;
          ptr = curr;
          curr = next;
     }
     newHead = ptr;
     return newHead;
}