#include <stdio.h>
#include <stdlib.h>

struct node
{
     int one;
     int two;
     struct node* next;
};

int main()
{
     struct node* head = (struct node*)malloc(sizeof(struct node));
     struct node* temp = head;
     struct node** newhead = (struct node**) (malloc (sizeof(struct node*)));
     head->one = 12;
     *newhead = head;
     printf("%d\n",**newhead);
     printf("%d\n",*newhead);
     printf("%d\n",head);
     printf("%d\n",*head);
     printf("%d\n",*temp);
     return 0;
}