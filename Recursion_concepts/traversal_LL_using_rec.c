#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
};

struct node *createlinklist(int n);
void display(struct node *head);
int traverse_LL_using_rec(struct node* head);
int rev_traverse_LL_using_rec(struct node* head);

int main()
{
     int n;
     struct node *head = NULL;
     printf("Enter how many nodes: ");
     scanf("%d", &n);
     head = createlinklist(n);
     display(head);
     printf("NULL");
     traverse_LL_using_rec(head);
     rev_traverse_LL_using_rec(head);
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

int traverse_LL_using_rec(struct node* root){
     printf("%d->",root->data);
     if (root->next)
     {
          traverse_LL_using_rec(root->next);
     }
}

int rev_traverse_LL_using_rec(struct node* root){
     if (root == NULL)
     {
          return 0;
     }
     else
     {
          rev_traverse_LL_using_rec(root->next);
     }
     printf("%d->",root->data);
}