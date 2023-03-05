#include <stdio.h>
#include <stdlib.h>
#define r 3
#define c 3

struct node
{
     int data;
     struct node* right;
     struct node* down;
};

struct node* LL_Matrix(int arr[r][c],int n){
     struct node* head = (struct node*)malloc(sizeof(struct node));
     head->data = arr[0][0];
     head->right = NULL;
     head->down = NULL;
     struct node* temp=head;
     for (int i = 0; i < r; i++)
     {
          struct node* temp2 = temp;
          for (int j = 0; j < c; j++)
          {
               if (j+1==n)
               {
                    temp->right = NULL;
               }
               else{
                    struct node* new = (struct node*)malloc(sizeof(struct node));
                    new->data = arr[i][j+1];
                    new->right = NULL;
                    new->down = NULL;
                    temp->right = new;
               }
               if (i+1 == n)
               {
                    temp->down = NULL;
               }
               else{
                    struct node* new = (struct node*)malloc(sizeof(struct node));
                    new->data = arr[i+1][j];
                    new->right = NULL;
                    new->down = NULL;
                    temp->down = new;
               }
               temp = temp->right;
          }
          temp = temp2;
          temp = temp->down;
     }
     return head;
}

void LL_traversal(struct node* head){
     struct node* temp = head;
     while (temp)
     {
          printf("%d->",temp->data);
          temp=temp->right;
     }
}

int main()
{
     int arr[r][c];
     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               printf("Enter data for %d,%d : ",i,j);
               scanf("%d",&arr[i][j]);
          }
     }
     int n=r;
     struct node* head = NULL;
     head = LL_Matrix(arr,n);
     LL_traversal(head);
     // printf("%d ",head->right->data);
     return 0;
}