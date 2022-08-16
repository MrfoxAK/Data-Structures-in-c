

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct Stack* ptr){
    if (ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack* ptr){
    if (ptr->top==ptr->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void push(struct Stack * ptr,int element){
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

int pop(struct Stack* ptr){
    int element = ptr->arr[ptr->top];
    if (isEmpty(ptr))
    {
        printf("Stack Underflow....\n");
    }
    else
    {
        ptr->top--;
        printf("%d element is popped\n",element);
    }
    return element;
}

int main()
{
    struct Stack * s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size=5;
    s->top=-1;
    s->arr = (int*)malloc(s->size*(sizeof(int)));
    printf("%d\n",isEmpty(s));
    printf("%d\n",isFull(s));
    push(s,19);
    push(s,78);
    push(s,278);
    push(s,8);
    push(s,728);
    push(s,72);
    pop(s);
//     pop(s);
//     pop(s);
    // pop(s);
    printf("%d\n",isEmpty(s));
    printf("%d\n",isFull(s));
    return 0;
}