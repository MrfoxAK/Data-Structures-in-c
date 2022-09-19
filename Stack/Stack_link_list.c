#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isFull(struct Node* top){
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    if (p==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Node* top){
    if (top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

struct Node* push(struct Node* top,int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    if (top==NULL)
    {
        top = temp;
        temp->next=NULL;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
    return top;
}


int pop(struct Node* tp){
    if (isEmpty(tp))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node* n = top;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}


void linklisttreversal(struct Node * top){
    struct Node* ptr = top;
    while (ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

int main()
{
    // struct Node *top = NULL;
    top=push(top,56);
    top=push(top,6);
    top=push(top,526);
    top=push(top,26);
    top=push(top,226);
    printf("%d is popped\n",pop(top));
    linklisttreversal(top);
    return 0;
}







// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node* next;
// };

// struct node* top = NULL;

// int isFull(struct node* top){
//     struct node* p = (struct node *)malloc(sizeof(struct node));
//     if (p==NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isEmpty(struct node* top){
//     if (top==NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// struct node * push(struct node* top,int data){
//     if (isFull(top))
//     {
//         printf("Stack Overflow\n");
//     }
//     else
//     {
//         struct node* n = (struct node *)malloc(sizeof(struct node));
//         n->data = data;
//         n->next = top;
//         top = n;
//         return top;
//     }
// }

// struct node * pop(struct node* tp){
//     if (isEmpty(tp))
//     {
//         printf("Stack Underflow\n");
//     }
//     else
//     {
//         struct node* n = top;
//         top = tp->next;
//         int x = n->data;
//         free(n);
//         return x;
//     }
// }

// void linklisttreversal(struct node * ptr){
//     while (ptr!=NULL)
//     {
//         printf("%d ",ptr->data);
//         ptr=ptr->next;
//     }
// }

// int main()
// {
//     top = push(top,67);
//     top = push(top,7);
//     top = push(top,27);
//     top = push(top,17);
//     int element = pop(top);
//     printf("Popped element is %d\n",element);
//     linklisttreversal(top);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node* next;
// };

// int isFull(struct node* top){
//     struct node* p = (struct node *)malloc(sizeof(struct node));
//     if (p==NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isEmpty(struct node* top){
//     if (top==NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// struct node * push(struct node* top,int data){
//     if (isFull(top))
//     {
//         printf("Stack Overflow\n");
//     }
//     else
//     {
//         struct node* n = (struct node *)malloc(sizeof(struct node));
//         n->data = data;
//         n->next = top;
//         top = n;
//         return top;
//     }
// }

// struct node * pop(struct node** top){
//     if (isEmpty(*top))
//     {
//         printf("Stack Underflow\n");
//     }
//     else
//     {
//         struct node* n = *top;
//         *top = (*top)->next;
//         int x = n->data;
//         free(n);
//         return x;
//     }
// }

// void linklisttreversal(struct node * ptr){
//     while (ptr!=NULL)
//     {
//         printf("%d ",ptr->data);
//         ptr=ptr->next;
//     }
// }

// int main()
// {
//     struct node* top = NULL;
//     top = push(top,67);
//     top = push(top,7);
//     top = push(top,27);
//     top = push(top,17);
//     int element = pop(&top);
//     printf("Popped element is %d\n",element);
//     linklisttreversal(top);

//     return 0;
// }
