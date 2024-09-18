#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 10

struct stack
{
     int top;
     char *arr;
     int size;
};

int isEmpty(struct stack *s)
{
     if (s->top == -1)
          return 1;
     else
          return 0;
}

int isFull(struct stack *s)
{
     if (s->top == s->size - 1)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

void push(struct stack *s, char data)
{
     if (isFull(s))
     {
          printf("Stack OverFlow....\n");
     }
     else
     {
          s->top++;
          s->arr[s->top] = data;
     }
}

int pop(struct stack *s)
{
     if (isEmpty(s))
     {
          printf("Stack Underflow\n");
     }
     else
     {
          int x;
          x = s->arr[s->top];
          s->top--;
          return x;
     }
}

int ispar(char str[])
{
     struct stack *s = NULL;
     s = (struct stack *)malloc(sizeof(struct stack));
     s->size = 20;
     s->top = -1;
     s->arr = (char *)malloc(s->size * sizeof(char));
     int i = 0;
     char p;
     for(i = 0; str[i] != '\0'; i++)
     {
          if (str[i]=='[' || str[i] == '{' || str[i] =='(')
          {
               push(s,str[i]);
          }
          // printf("%c\n",s->arr[s->top]);
          else if (str[i]==']' || str[i] == '}' || str[i] ==')')
          {
               p = pop(s);
               if(str[i] == ']' && p == '['){
                    continue;
               }
               else if(str[i] == '}' && p == '{'){
                    continue;
               }
               else if(str[i] == ')' && p == '('){
                    continue;
               }
               else{
                    return 0;
               }
          }
     }
     if (isEmpty(s))
          return 1;
     else
          return 0;
}

int main()
{
     char str[] = "[(])";
     if(ispar(str))
          printf("True\n");
     else
          printf("False\n");
     return 0;
}