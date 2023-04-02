#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

int arr[4];
int i = 0;

void inOrder(struct node *root)
{
     if (root != NULL)
     {
          inOrder(root->left);
          printf("%d ", root->data);
          inOrder(root->right);
     }
}

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

void Sort(int array[], int size)
{
     for (int step = 0; step < size - 1; ++step)
     {
          for (int i = 0; i < size - step - 1; ++i)
          {
               if (array[i] > array[i + 1])
               {
                    int temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
               }
          }
     }
}

void cnvt(struct node *root)
{
     if (root != NULL)
     {
          cnvt(root->left);
          root->data = arr[i];
          i++;
          // printf("%d ", root->data);
          cnvt(root->right);
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

int main()
{
     struct node *root = NULL;
     root = create();
     inOrder_traversal(root);
     inOrder(root);
     printf("\n");
     i = 0;
     Sort(arr, 4);
     cnvt(root);
     inOrder(root);
     return 0;
}