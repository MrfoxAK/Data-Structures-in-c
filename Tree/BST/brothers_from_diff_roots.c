#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

struct node *GetNewNode(int data)
{
     struct node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));
     newnode->data = data;
     newnode->left = NULL;
     newnode->right = NULL;
     return newnode;
}

struct node *insert(struct node *root, int data)
{
     if (root == NULL)
     {
          root = GetNewNode(data);
     }
     else if (root->data > data)
     {
          root->left = insert(root->left, data);
     }
     else
     {
          root->right = insert(root->right, data);
     }
     return root;
}

int search(struct node* root,int data){
     if (root==NULL)
     {
          return 0;
     }
     else if (root->data==data)
     {
          return 1;
     }
     else if (data<root->data)
     {
          return search(root->left,data);
     }
     else
     {
          return search(root->right,data);
     }
}

int arr1[10];
int arr2[10];
int sum = 16;

void print_array1(struct node* root){
     static int i = 0;
     if (root == NULL)
     {
          return;
     }
     print_array1(root->left);
     // printf("%d ",root->data);
     arr1[i] = root->data;
     i++;
     print_array1(root->right);
}

void print_array2(struct node* root){
     static int i = 0;
     if (root == NULL)
     {
          return;
     }
     print_array2(root->left);
     // printf("%d ",root->data);
     arr2[i] = root->data;
     i++;
     print_array2(root->right);
}

int is_present(int arr[], int data){
     for (int i = 0; i < 7; i++)
     {
          if(data == arr[i]){
               return 1;
          }
     }
     return 0;
}

int main()
{
     struct node *root1 = NULL;
     root1 = insert(root1, 5);
     root1 = insert(root1, 3);
     root1 = insert(root1, 7);
     root1 = insert(root1, 2);
     root1 = insert(root1, 4);
     root1 = insert(root1, 6);
     root1 = insert(root1, 8);

     // printf("%d",root1->right->left->data);
     print_array1(root1);

     struct node *root2 = NULL;
     root2 = insert(root2, 10);
     root2 = insert(root2, 6);
     root2 = insert(root2, 15);
     root2 = insert(root2, 3);
     root2 = insert(root2, 8);
     root2 = insert(root2, 11);
     root2 = insert(root2, 18);

     // printf("%d",root2->right->right->data);
     print_array2(root2);

     for (int i = 0; i < 7; i++)
     {
          printf("%d ",arr1[i]);
     }
     printf("\n");
     for (int i = 0; i < 7; i++)
     {
          printf("%d ",arr2[i]);
     }
     printf("\n");

     // Main logic
     for (int i = 0; i < 7; i++)
     {
          int curr = arr1[i];
          int ex = sum - curr;
          if (is_present(arr2, ex))
          {
               printf("(%d, %d) ",curr,ex);
          }
     }
     return 0;
}