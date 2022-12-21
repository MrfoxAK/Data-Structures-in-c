#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
     int top;
     char* arr;
     int size;
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

int isOP(char ch)
{
     if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
          return 1;
     else
          return 0;
}

char* infix2postfix(char* s){
     int i=0,j=0;
     struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
     sp->size = 10;
     sp->top = -1;
     sp->arr = (char *)malloc(sp->size * sizeof(char));
     char * post = (char*)malloc(sizeof(char)*(strlen(s) + 1));
     while (s[i]!='\0')
     {
          if (!isOP(s[i]))
          {
               post[j] = s[i];
               i++;
               j++;
          }
          else
          {
               if (precedence(s[i])>precedence(stackTop(sp)))
               {
                    push(sp,s[i]);
                    i++;
               }
               else{
                    post[j] = pop(sp);
                    j++;
               }
          }
     }
     while (!isEmpty(sp))
     {
          post[j] = pop(sp);
          j++;
     }
     post[j] = '\0';
     return post;
}

int main()
{
     char * s = "x-y/z-k*d";
     printf("postfix is %s", infix2postfix(s));
     return 0;
}