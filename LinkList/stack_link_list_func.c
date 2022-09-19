#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int data;
     struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr)
{
     while (ptr != NULL)
     {
          printf("Element: %d\n", ptr->data);
          ptr = ptr->next;
     }
}

int isEmpty(struct Node *top)
{
     if (top == NULL)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

int isFull(struct Node *top)
{
     struct Node *p = (struct Node *)malloc(sizeof(struct Node));
     if (p == NULL)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

struct Node *push(struct Node *top, int x)
{
     if (isFull(top))
     {
          printf("Stack Overflow\n");
     }
     else
     {
          struct Node *n = (struct Node *)malloc(sizeof(struct Node));
          n->data = x;
          n->next = top;
          top = n;
          return top;
     }
}

int pop(struct Node *tp)
{
     if (isEmpty(tp))
     {
          printf("Stack Underflow\n");
     }
     else
     {
          struct Node *n = tp;
          top = (tp)->next;
          int x = n->data;
          free(n);
          return x;
     }
}

int peek(struct Node *top, int pos)
{
     struct Node *ptr = top;
     int i = 0;
     while (i < pos - 1)
     {
          ptr = ptr->next;
          i++;
     }
     return ptr->data;
}

int stackTop(struct Node *top)
{
     return top->data;
}

int main()
{
     int choice, val, element, pos;
     while (1)
     {
          printf("Enter you choice : \n");
          printf("1.Push\t");
          printf("2.Pop\t");
          printf("3.Peek\t");
          printf("4.Stacktop\t");
          printf("5.Traversal\t");
          printf("6.Exit\n");
          scanf("%d", &choice);
          switch (choice)
          {
          case 1:
               printf("Enter the value : ");
               scanf("%d", &val);
               top = push(top, val);
               break;
          case 2:
               element = pop(top);
               printf("%d : element is popped\n", element);
               break;
          case 3:
               printf("Enter the position: ");
               scanf("%d", &pos);
               printf("The element is : %d\n", peek(top, pos));
               break;
          case 4:
               printf("The StackTop value is : %d\n", stackTop(top));
               break;
          case 5:
               linkedListTraversal(top);
               break;
          case 6:
               goto end;
               break;
          }
     }
end:
     return 0;
}








































































