#include <stdio.h>
#include <stdlib.h>

struct stack
{
     int * arr;
     int size;
     int top;
};

void display(struct stack* ptr){
     for (int i = ptr->top; i >= 0; i--)
     {
          printf("|%d|\n",ptr->arr[i]);
     }
}

int isEmpty(struct stack * p){
     if (p->top==-1)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}

int isFull(struct stack * p){
     if(p->top==p->size){
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
     struct stack * s1;
     s1 = (struct stack*)malloc(sizeof(struct stack));
     s1->size=50;
     s1->top=-1;
     s1->arr = (int*)malloc((s1->size)*sizeof(int));
     int index,data;
     int choice;
     do
     {
          printf("Enter Your Choice: 1.Push 2.pop 3.peek 4.display\n");
          scanf("%d",&choice);
          switch (choice)
          {
          case 1:
          printf("Enter Data You Want To Push: ");
          scanf("%d",&data);
               push(s1,data);
               break;
          case 2:
               printf("%d : Element Is Popped\n",pop(s1));
               break;
          
          case 3:
          printf("Enter Position : ");
          scanf("%d",&index);
               printf("The element at %d is : %d\n",index,peek(s1,index));
               break;
          case 4:
          display(s1);
               break;
          
          default:
          printf("Invalid Choice....");
               break;
          }
     } while (choice);

     return 0;
}