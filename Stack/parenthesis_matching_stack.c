#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
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
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
 
int parenthesisMatch(char * exp){
    // Create and initialize the stack
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
 
 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp, '(');
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp); 
        }
    }
 
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}
int main()
{
    char * exp = "((8)(*--$$9))";
    // Check if stack is empty
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>

// struct stack
// {
//      int size;
//      int top;
//      int *arr;
// };

// int isEmpty(struct stack *ptr)
// {
//      if (ptr->top == -1)
//      {
//           return 1;
//      }
//      else
//      {
//           return 0;
//      }
// }

// int isFull(struct stack *ptr)
// {
//      if (ptr->top == ptr->size - 1)
//      {
//           return 1;
//      }
//      else
//      {
//           return 0;
//      }
// }

// void push(struct stack * ptr,int val){
//      if (isFull(ptr))
//      {
//           printf("Stack Overflow! can't push %d to the stack\n",val);
//      }
//      else
//      {
//           ptr->top++;
//           ptr->arr[ptr->top] = val;
//      }
// }

// int pop(struct stack * ptr){
//      if (isEmpty(ptr))
//      {
//           printf("Stack Underflow! can't push to the stack\n");
//           return -1;
//      }
//      else
//      {
//           int val = ptr->arr[ptr->top];
//           ptr->top--;
//           return val;
//      }
// }

// int main()
// {
//      char s[100];
//      struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
//      sp->size = 10;
//      sp->top = -1;
//      sp->arr = (int *)malloc(sp->size * sizeof(int));
//      printf("Enter the expression : ");
//      gets(s);
//      int i = 0;
//      while (s[i]!='\0')
//      {
//           if(s[i]=='('){
//                push(sp,1);
//           }
//           else if (s[i]==')')
//           {
//                pop(sp);
//           }
//           i++;
//      }
//      if (isEmpty(sp))
//      {
//           printf("match\n");
//      }
//      else{
//           printf("Unmatch\n");
//      }
//      return 0;
// }
