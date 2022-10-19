#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

void Postorder_traversal(struct node * root){
     if (root!=NULL)
     {
          Postorder_traversal(root->left);
          Postorder_traversal(root->right);
          printf("%d ",root->data);
     }
}

struct node* create(){
     int c=1;
     struct node * newnode;
     newnode=(struct node*)malloc(sizeof(struct node));
     printf("Enter data (-1 for blank) : ");
     scanf("%d",&c);
     if (c==-1)
     {
          return 0;
     }
     newnode->data=c;
     printf("Left child of %d : ",c);
     newnode->left=create();
     printf("Right child of %d : ",c);
     newnode->right=create();
     return newnode;
}

int findDepth(struct node* root){
     int d=0;
     while (root!=NULL)
     {
          d++;
          root=root->left;
     }
     return d;
}

int Check_Perfect_BT(struct node* root,int d,int level){
     if (root==NULL)
     {
          return 1;
     }
     else if (root->left == NULL && root->right == NULL)
     {
          return (d == level+1);
     }
     else if (root->left == NULL || root->right == NULL)
     {
          return 0;
     }
     else
     {
          return Check_Perfect_BT(root->left,d,level+1) && Check_Perfect_BT(root->right,d,level+1);
     }
}

int isPerfect(struct node* root){
     int d = findDepth(root);
     return Check_Perfect_BT(root,d,0);
}

int main()
{
     struct node * root = NULL;
     root = create();
     Postorder_traversal(root);
     if(isPerfect(root)){
          printf("YES\n");
     }
     else
     {
          printf("NO\n");
     }
     return 0;
}