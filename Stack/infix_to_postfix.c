#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
     int size;
     int top;
     char *arr;
};


int stackTop(struct stack *sp)
{
     return sp->arr[sp->top];
}

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

void push(struct stack *ptr, char val)
{
     if (isFull(ptr))
     {
          printf("Stack Overflow! Cannot push %d to the stack\n", val);
     }
     else
     {
          ptr->top++;
          ptr->arr[ptr->top] = val;
     }
}

char pop(struct stack *ptr)
{
     if (isEmpty(ptr))
     {
          printf("Stack Underflow! Cannot pop from the stack\n");
          return -1;
     }
     else
     {
          char val = ptr->arr[ptr->top];
          ptr->top--;
          return val;
     }
}

int precedence(char ch)
{
     if (ch == '*' || ch == '/')
          return 3;
     else if (ch == '+' || ch == '-')
          return 2;
     else
          return 0;
}

int isOperator(char ch)
{
     if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
          return 1;
     else
          return 0;
}

char * infix_2_postfix(char * infix){
     struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
     sp->size = 10;
     sp->top = -1;
     sp->arr = (char *)malloc(sp->size*(sizeof(char)));
     char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
     int i=0;
     int j=0;
     while (infix[i]!='\0')
     {
          if (isOperator(infix[i]))
          {
               if (isEmpty(sp))
               {
                    push(sp,infix[i]);
                    i++;
               }
               else
               {
                    if (precedence(stackTop(sp))<precedence(infix[i]))
                    {
                         push(sp,infix[i]);
                         i++;
                    }
                    else
                    {
                         char p = pop(sp);
                         postfix[j] = p;
                         j++;
                    }
               }
          }
          else
          {
               postfix[j] = infix[i];
               j++;
               i++;
          }
     }
     while (!isEmpty(sp))
     {
          char p = pop(sp);
          postfix[j] = p;
          j++;
     }
     postfix[j] = '\0';
     return postfix;
}

int main()
{
     char * infix = "x-y/z-k*d";
     printf("postfix is %s", infix_2_postfix(infix));
     return 0;
}