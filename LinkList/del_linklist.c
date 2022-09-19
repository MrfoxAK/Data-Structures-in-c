#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node *next;
};

// Traversal
void linklisttraversal(struct Node *ptr)
{
     while (ptr != NULL)
     {
          printf("%d->", ptr->data);
          ptr = ptr->next;
     }
     printf("NULL\n");
}

// case 1 : delete the first node
struct Node *delete1st(struct Node *head)
{
     struct Node *ptr = head;
     head = head->next;
     free(ptr);
     return head;
}

// case 2: delete btwn nodes
struct Node *deleteAtIndex(struct Node *head, int index)
{
     struct Node *p = head;
     struct Node *q = head->next;
     for (int i = 0; i < index - 2; i++)
     {
          p = p->next;
          q = q->next;
     }
     p->next = q->next;
     free(q);
     return head;
}

// case 3: delete at the end
struct Node *deleteAtEnd(struct Node *head)
{
     struct Node *p = head;
     struct Node *q = head->next;
     while (q->next != NULL)
     {
          p = p->next;
          q = q->next;
     }
     p->next = NULL;
     free(q);
     return head;
}

// case 4: delete at value
struct Node *deleteAtValue(struct Node *head, int value)
{
     struct Node *p = head;
     struct Node *q = head->next;
     while (q->data != value && q->next != NULL)
     {
          p = p->next;
          q = q->next;
     }
     if (q->data == value)
     {
          p->next = q->next;
          free(q);
     }
     return head;
}

struct Node *create(struct Node *head)
{
     struct Node *newNode;
     struct Node *temp;
     int choice = 2;
     while (choice)
     {
          newNode = (struct Node *)malloc(sizeof(struct Node));
          printf("Enter data: ");
          scanf("%d", &newNode->data);
          newNode->next = NULL;
          if (head == NULL)
          {
               head = temp = newNode;
          }
          else
          {
               temp->next = newNode;
               temp = newNode;
          }
          printf("Do you want to continue (1/0) : ");
          scanf("%d", &choice);
     }
     return head;
}

int main()
{
     int pos;
     struct Node *head = NULL;
     int c;
     while (1)
     {
          printf("Enter the choice: 1.for create 2.display 3.delete_1st 4.delete_pos 5.delete_end 0.for exit : ");
          scanf("%d", &c);
          switch (c)
          {
          case 1:
               head = create(head);
               break;
          case 2:
               linklisttraversal(head);
               break;
          case 3:
               head = delete1st(head);
               break;
          case 4:
               printf("Enter pos: ");
               scanf("%d", &pos);
               head = deleteAtIndex(head, pos);
               break;
          case 5:
               head = deleteAtEnd(head);
               break;
          case 0:
               exit(0);
               break;
          default:
               printf("Invalid Choice\n");
          }
     }
     return 0;
}