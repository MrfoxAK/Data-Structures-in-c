#include <stdio.h>
#include <stdlib.h>

struct stack
{
     int top;
     int *arr;
     int size;
};

int isEmpty(struct stack *ptr)
{
     if (ptr->top == -1)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

int isFull(struct stack *ptr)
{
     if (ptr->top == ptr->size - 1)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

void *push(struct stack *p, int data)
{
     if (isFull(p))
     {
          printf("Stack OverFlow....\n");
     }
     else
     {
          p->top++;
          p->arr[p->top] = data;
     }
}

int pop(struct stack *p)
{
     if (isEmpty(p))
     {
          printf("Stack Underflow\n");
     }
     else
     {
          int x;
          x = p->arr[p->top];
          p->top--;
          return x;
     }
}

int main()
{
     struct stack *s = NULL;
     s = (struct stack *)malloc(sizeof(struct stack));
     s->size = 5;
     s->top = -1;
     s->arr = (int *)malloc(s->size * (sizeof(int)));
     printf("The stack is %d\n", isEmpty(s));
     printf("The stack is %d\n", isFull(s));
     push(s, 1);
     push(s, 12);
     push(s, 11);
     push(s, 123);
     printf("%d element popped\n", pop(s));
     printf("%d element popped\n", pop(s));
     printf("%d element popped\n", pop(s));
     printf("%d element popped\n", pop(s));
     printf("%d element popped\n", pop(s));
     // printf("The stack is %d\n", isEmpty(s));
     // printf("The stack is %d\n", isFull(s));
     return 0;
}