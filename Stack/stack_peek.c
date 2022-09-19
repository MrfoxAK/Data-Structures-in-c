#include <stdio.h>
#include <stdlib.h>

struct stack
{
     int size;
     int top;
     int * arr;
};

int isEmpty(struct stack* ptr){
     if (ptr->top==-1)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

int isFull(struct stack* ptr){
     if (ptr->top == ptr->size-1)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

void push(struct stack * ptr,int val){
     if (isFull(ptr))
     {
          printf("Stack Overflow! can't push %d to the stack\n",val);
     }
     else
     {
          ptr->top++;
          ptr->arr[ptr->top] = val;
     }
}

int pop(struct stack * ptr){
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
     struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
     sp->size = 50;
     sp->top = -1;
     sp->arr = (int *)malloc(sp->size * sizeof(int));
     printf("Stack has been created successfully\n");
     // printf("%d\n", isEmpty(sp));
     // printf("%d\n",isFull(sp));
     push(sp,56);
     push(sp,1156);
     push(sp,561);
     push(sp,56);
     push(sp,5622);
     push(sp,56);
     push(sp,56);
     push(sp,56);
     push(sp,56);
     push(sp,516); //--> pushed 10 values
     push(sp,526); // stack overflow
     push(sp,56); // stack overflow
     push(sp,216); // stack overflow
     push(sp,96); // stack overflow
     push(sp,556); // stack overflow
     push(sp,6); // stack overflow
     // printf("After pushing.......\n");
     // printf("%d\n", isEmpty(sp));
     // printf("%d\n",isFull(sp));
     // printf("Popped %d from the Stack\n",pop(sp));
     // printf("Popped %d from the Stack\n",pop(sp));
     // printf("Popped %d from the Stack\n",pop(sp));
     // printf("Popped %d from the Stack\n",pop(sp));
     // printf("Popped %d from the Stack\n",pop(sp));
     // printf("Popped %d from the Stack\n",pop(sp));
     // printf("Popped %d from the Stack\n",pop(sp));
     // printf("Popped %d from the Stack\n",pop(sp));
     // printf("Popped %d from the Stack\n",pop(sp));
     // printf("Popped %d from the Stack\n",pop(sp));
     // printf("Popped %d from the Stack\n",pop(sp));
     for (int j = 1; j <= sp->top+1; j++)
     {
          printf("The value at %dth position is %d\n",j,peek(sp,j));
     }
     
     return 0;
}