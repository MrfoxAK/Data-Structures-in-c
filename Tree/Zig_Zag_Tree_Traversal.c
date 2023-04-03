#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

void inOrder_traversal(struct node *root)
{
     if (root != NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ", root->data);
          inOrder_traversal(root->right);
     }
}
int f,r;

struct node** createQueue(){
     struct node** queue  = (struct node**)malloc(sizeof(struct node*)*MAX_Q_SIZE);
     f=r=0;
     return queue;
}

int isEmpty(struct node** q){
     if (f == r)
          return 1;
     else
          return 0;
}

void enQueue(struct node** q, struct node* n){
     q[r] = n;
     r++;
}

struct node* deQueue(struct node** q){
     f++;
     return q[f-1];
}

void level_order(struct node* root){
     int level = 1;
     struct node** q = createQueue();
     struct node* curr = NULL;
     enQueue(q,root);
     enQueue(q,NULL);
     printf("%d ",root->data);
     int i=0;
     while (!isEmpty(q))
     {
          curr = deQueue(q);
          if (curr==NULL)
          {
               if (isEmpty(q))
               {
                    break;
               }
               else{
                    enQueue(q,NULL);
                    level++;
                    if (level%2==0)
                    {
                         i=f;
                         while (q[i]!=NULL)
                         {
                              i++;
                         }
                         // printf("%d ",i);
                         while (i>=f+1)
                         {
                              int val = q[i-1]->data;
                              printf("%d ",val);
                              i--;
                         }
                    }
                    else{
                         i=f;
                         while (q[i]!=NULL)
                         {
                              int val = q[i]->data;
                              printf("%d ",val);
                              i++;
                         }
                    }
                    // printf("\n");
               }
          }
          else{
               if (curr->left!=NULL)
               {
                    enQueue(q,curr->left);
               }
               if (curr->right!=NULL)
               {
                    enQueue(q,curr->right);
               }
          }
     }
}

struct node *insert(struct node *root, int data)
{
     if (root == NULL)
     {
          struct node *n;
          n = (struct node *)malloc(sizeof(struct node));
          n->data = data;
          n->left = NULL;
          n->right = NULL;
          root = n;
          // return root;
     }
     else if (data < root->data)
     {
          root->left = insert(root->left, data);
     }
     else
     {
          root->right = insert(root->right, data);
     }
     return root;
}

int main()
{
     struct node *root = NULL;
     root = insert(root, 15);
     root = insert(root, 10);
     root = insert(root, 20);
     root = insert(root, 25);
     root = insert(root, 8);
     root = insert(root, 12);
     root = insert(root, 120);
     root = insert(root, 1);
     root = insert(root, 9);
     root = insert(root, 14);
     // inOrder_traversal(root);
     level_order(root);
     return 0;
}