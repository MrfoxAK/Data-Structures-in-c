#include <stdio.h>
#include <stdlib.h>

struct Stack
{
     int size;
     int top;
     int *arr;
};

int isEmpty(struct Stack *ptr)
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

int isFull(struct Stack *ptr)
{
     if (ptr->top == ptr->size)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

void push(struct Stack *ptr, int element)
{
     if (isFull(ptr))
     {
          printf("Stack OverFlow....\n");
     }
     else
     {
          ptr->top++;
          ptr->arr[ptr->top] = element;
     }
}

int pop(struct Stack *ptr)
{
     int element = ptr->arr[ptr->top];
     if (isEmpty(ptr))
     {
          printf("Stack Underflow....\n");
     }
     else
     {
          ptr->top--;
          // printf("%d element is popped\n", element);
     }
     return element;
}

int peek(struct Stack *ptr, int pos)
{
     if (ptr->top - pos + 1 < 0)
     {
          printf("Not a valid pos\n");
     }
     else
     {
          return ptr->arr[(ptr->top) + 1 - pos];
     }
}

int stackTop(struct Stack *ptr)
{
     return ptr->arr[ptr->top];
}

int stackBottom(struct Stack *ptr)
{
     return ptr->arr[0];
}

int main()
{
     struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
     s->size = 50;
     s->top = -1;
     s->arr = (int *)malloc(s->size * (sizeof(int)));
     int u;
     int i = 0;
     int visited[7] = {0, 0, 0, 0, 0, 0, 0};
     int a[7][7] = {
         {0, 1, 1, 1, 0, 0, 0},
         {1, 0, 0, 1, 0, 0, 0},
         {1, 1, 0, 1, 1, 0, 0},
         {1, 0, 1, 0, 1, 0, 0},
         {0, 0, 1, 1, 0, 1, 1},
         {0, 0, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 1, 0, 0}};
     printf("%d ", i);
     visited[i] = 1;
     push(s,i);
     while (!isEmpty(s))
     {
          int node = pop(s);
          for (int j = 0; j < 7; j++)
          {
               if (a[node][j] == 1 && visited[j] == 0)
               {
                    printf("%d ", j);
                    visited[j] = 1;
                    push(s,j);
               }
          }
     }
     return 0;
}