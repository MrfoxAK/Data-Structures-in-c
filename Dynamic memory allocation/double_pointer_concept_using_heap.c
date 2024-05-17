#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

int f,r;

struct node** createQueue(){
     struct node** s = (struct node**)malloc(4*sizeof(struct node*));
     f = r = 0;
     return s;
}

void enqueue(struct node** s, struct node* n){
     s[f] = n;
}

int main()
{
     struct node* temp = (struct node*)malloc(sizeof(struct node));
     temp->data = 5;
     struct node* temp1 = (struct node*)malloc(sizeof(struct node));
     temp1->data = 15;
     struct node* temp2 = (struct node*)malloc(sizeof(struct node));
     temp2->data = 25;

     struct node** s1 = createQueue();
     
     enqueue(s1,temp2);

     printf("%d",s1[0]->data);

     return 0;
}