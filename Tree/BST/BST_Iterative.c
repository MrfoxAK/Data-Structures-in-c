#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

void inOrder_traversal(struct node * root){
     if (root!=NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ",root->data);
          inOrder_traversal(root->right);
     }
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

int main()
{
     struct node* root=NULL;
     struct node* newnode;
     struct node* temp;
     int n,data;
     printf("Enter the no.of nodes: ");
     scanf("%d",&n);
     for (int i = 0; i < n; i++)
     {
          newnode=(struct node*)malloc(sizeof(struct node));
          printf("Enter data: ");
          scanf("%d",&newnode->data);
          newnode->left=NULL;
          newnode->right=NULL;
          if (i==0)
          {
               root=newnode;
          }
          else
          {
               temp=root;
               while (1)
               {
                    if(newnode->data>temp->data){
                         if (temp->right==NULL)
                         {
                              temp->right=newnode;
                              break;
                         }
                         else
                         {
                              temp=temp->right;
                         }
                    }
                    else
                    {
                         if (temp->left==NULL)
                         {
                              temp->left=newnode;
                              break;
                         }
                         else
                         {
                              temp=temp->left;
                         }
                    }
               }
          }
     }
     // if (search(root,5))
     // {
     //      printf("Yes\n");
     // }
     // else
     // {
     //      printf("No\n");
     // }
     inOrder_traversal(root);
     return 0;
}