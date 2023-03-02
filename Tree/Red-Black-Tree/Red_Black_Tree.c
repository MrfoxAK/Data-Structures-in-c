#include <stdio.h>
#include <stdlib.h>

struct node
{
     int d;   //data
     int c;   //color 1 for red 0 for black
     struct node* p;    //parent
     struct node* l;    //left
     struct node* r;    //right
};

// global root for the entire tree
struct node* root = NULL;

void rightrotate(struct node* x){
     struct node* y = x->l;
     struct node* t2 = y->r;
     
}

int main()
{
     
     return 0;
}