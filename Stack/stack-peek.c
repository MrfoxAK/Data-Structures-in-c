#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct stack
{
     int size;
     int top;
     int *arr;
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

void push(struct stack *ptr, int val)
{
     if (isFull(ptr))
     {
          printf("Stack Overflow! can't push %d to the stack\n", val);
     }
     else
     {
          ptr->top++;
          ptr->arr[ptr->top] = val;
     }
}

int pop(struct stack *ptr)
{
     if (isEmpty(ptr))
     {
          printf("Stack Underflow! can't push to the stack\n");
          return -1;
     }
     else
     {
          int val = ptr->arr[ptr->top];
          ptr->top--;
          return val;
     }
}

int peek(struct stack* sp,int i){
     if (sp->top-i+1<0)
     {
          printf("Not a valid position for the stack\n");
          return -1;
     }
     else
     {
          return sp->arr[sp->top-i+1];
     }
     
}

int main()
{
     int choice, val;
     struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
     do
     {
          printf("\n 1. PUSH");
          printf("\n 2. PEEK");
          printf("\n 3. DISPLAY");
          printf("\n 4. EXIT");
          printf("\n Enter your option : ");
          scanf("%d", &choice);
          switch (choice)
          {
          case 1:
               printf("\nEnter the number to be pushed on stack: ");
               scanf("%d", &val);
               push(sp, val);
               break;
          case 2:
               pop(sp);
          case 3:
               for (int j = 1; j <= sp->top + 1; j++)
               {
                    printf("The value at %dth position is %d\n", j, peek(sp, j));
               }
               break;
          }
     } while (choice != 4);

     return 0;
}