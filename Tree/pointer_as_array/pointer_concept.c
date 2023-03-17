#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
};


int main()
{
     struct node* n=NULL;
     n = (struct node*)malloc(sizeof(struct node));
     printf("%d\n",n);
     struct node** np=&n;
     printf("%d\n",np[0]);
     int * p;
     p = (int*)malloc(sizeof(int)*5);
     for (int i = 0; i < 5; i++)
     {
          p[i] = i;
     }
     for (int i = 0; i < 5; i++)
     {
          printf("%d ",p[i]);
     }
     return 0;
}