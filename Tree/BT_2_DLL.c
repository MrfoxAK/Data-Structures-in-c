#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

int arr[MAX];
int i = 0;


void inOrder_traversal(struct node *root)
{
     if (root != NULL)
     {
          inOrder_traversal(root->left);
          // printf("%d ", root->data);
          arr[i] = root->data;
          i++;
          inOrder_traversal(root->right);
     }
}

struct node *create()
{
     int c = 1;
     struct node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));
     printf("Enter data (-1 for blank) : ");
     scanf("%d", &c);
     if (c == -1)
     {
          return 0;
     }
     newnode->data = c;
     printf("Left child of %d : ", c);
     newnode->left = create();
     printf("Right child of %d : ", c);
     newnode->right = create();
     return newnode;
}

struct node* BT_2_DLL(struct node * head, int n){
     struct node* temp = NULL;
     struct node* new = NULL;
     i = 0;
     while (i<n)
     {
          new = (struct node*)malloc(sizeof(struct node));
          new->data = arr[i];
          new->left = NULL;
          new->right = NULL;
          if (head == NULL)
          {
               head = temp = new;
          }
          else{
               temp->right = new;
               new->left = temp;
               temp = new;
          }
          i++;
     }
     return head;
}

void linklisttreversal(struct node *ptr)
{
     struct node* last;
     printf("\nTraversal in forward direction \n");
     while (ptr != NULL)
     {
          printf("%d ", ptr->data);
          last = ptr;
          ptr = ptr->right;
     }
     printf("\n");
     printf("\nTraversal in reverse direction \n");
     while (last!=NULL)
     {
          printf("%d ",last->data);
          last = last->left;
     }
}

int main()
{
     int c = 0;
     struct node *root = NULL;
     root = create();
     inOrder_traversal(root);
     for (int j = 0; j < MAX; j++)
     {
          if (arr[j] != 0)
          {
               c++;
          }
     }
     struct node* head = NULL;
     head = BT_2_DLL(head, c);
     linklisttreversal(head);
     return 0;
}