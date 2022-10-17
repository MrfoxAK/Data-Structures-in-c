#include <stdio.h>
#include <stdlib.h>

struct Stack
{
     char *arr;
     int size;
     int top;
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
    if (ptr->top == ptr->size - 1)
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

char pop(struct Stack *ptr)
{
     char element = ptr->arr[ptr->top];
     if (isEmpty(ptr))
     {
          // printf("Stack Underflow....\n");
     }
     else
     {
          ptr->top--;
          // printf("%c element is popped\n", element);
     }
     return element;
}

int stackTop(struct Stack *ptr)
{
     return ptr->arr[ptr->top];
}

int match(char str[])
{
     struct Stack* s;
     s = (struct Stack*)malloc(sizeof(struct Stack));
     s->top=-1;
     s->size=10;
     s->arr=(char*)malloc(s->size*(sizeof(char)));
     int i = 0;
     while (str[i] != '\0')
     {
          if (str[i]=='(' || str[i]=='{' || str[i]=='[')
          {
               push(s,str[i]);
          }
          else if (str[i]==')' || str[i]=='}' || str[i]==']')
          {
               char p = pop(s);
               if (str[i]==')')
               {
                    if (p!='(')
                    {
                         return 0;
                         break;
                    }
               }
               else if (str[i]=='}')
               {
                    if (p!='{')
                    {
                         return 0;
                         break;
                    }
               }
               else if (str[i]==']')
               {
                    if (p!='[')
                    {
                         return 0;
                         break;
                    }
               }
          }
          i++;
     }
     if (isEmpty(s))
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

int main()
{     
     char str[] = "{o(so())[j]}";
     if(match(str)){
          printf("Match\n");
     }
     else{
          printf("Not Match\n");
     }
     return 0;
}