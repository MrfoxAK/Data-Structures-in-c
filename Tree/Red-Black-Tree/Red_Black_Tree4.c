#include <stdio.h>
#include <stdlib.h>

struct node
{
     int d;
     struct node *l;
     struct node *r;
     struct node *p;
     int c;
};

struct node *root = NULL;

void inorder(struct node *trav)
{
     if (trav == NULL)
          return;
     inorder(trav->l);
     printf("%d ", trav->d);
     inorder(trav->r);
}

struct node *bst(struct node *root, struct node *temp)
{
     if (root == NULL)
     {
          root = temp;
          return root;
     }
     else if (temp->d < root->d)
     {
          root->l = bst(root->l, temp);
          root->l->p = root;
     }
     else if (temp->d > root->d)
     {
          root->r = bst(root->r, temp);
          root->r->p = root;
     }
     return root;
}

void rightrotate(struct node *temp)
{
     struct node* left = temp->l;
     temp->l = left->r;
     if(temp->l){
          temp->l->p = temp;
     }
     left->p = temp->p;
     if(!temp->p){
          root = left;
     }
     else if (temp->p->l = temp)
     {
          temp->p->l = left;
     }
     else{
          temp->p->r = left;
     }
     left->r = temp;
     temp->p = left;
}

void leftrotate(struct node *temp)
{
     struct node *right = temp->r;
     temp->r = right->l;
     if (temp->r)
          temp->r->p = temp;
     right->p = temp->p;
     if (!temp->p)
          root = right;
     else if (temp == temp->p->l)
          temp->p->l = right;
     else
          temp->p->r = right;
     right->l = temp;
     temp->p = right;
}

void fixup(struct node *root, struct node *pt)
{
     struct node *parent_pt = NULL;
     struct node *grand_parent_pt = NULL;
     while ((pt->c != 0) && (pt != root) && (pt->p->c == 1))
     {
          parent_pt = pt->p;
          grand_parent_pt = pt->p->p;
          if (grand_parent_pt->l == parent_pt)
          {
               struct node *uncle_pt = grand_parent_pt->r;
               if (uncle_pt != NULL && uncle_pt->c == 1)
               {
                    grand_parent_pt->c = 1;
                    uncle_pt->c = 0;
                    parent_pt->c = 0;
                    pt = grand_parent_pt;
               }
               else
               {
                    if (parent_pt->l == pt)
                    {
                         rightrotate(grand_parent_pt);
                         int t = grand_parent_pt->c;
                         grand_parent_pt->c = parent_pt->c;
                         parent_pt->c = t;
                         pt = parent_pt;
                    }
                    else
                    {
                         leftrotate(parent_pt);
                         pt = parent_pt;
                         parent_pt = pt->p;
                    }
               }
          }
          else
          {
               struct node *uncle_pt = grand_parent_pt->l;
               if (uncle_pt != NULL && uncle_pt->c == 1)
               {
                    grand_parent_pt->c = 1;
                    parent_pt->c = 0;
                    uncle_pt->c = 0;
                    pt = grand_parent_pt;
               }
               else
               {
                    if (parent_pt->r == pt)
                    {
                         leftrotate(grand_parent_pt);
                         int t = parent_pt->c;
                         parent_pt->c = grand_parent_pt->c;
                         grand_parent_pt->c = t;
                         pt = parent_pt;
                    }
                    else
                    {
                         rightrotate(parent_pt);
                         pt = parent_pt;
                         parent_pt = pt->p;
                         // leftrotate(grand_parent_pt);
                         // pt = parent_pt;
                    }
               }
          }
     }
}

int main()
{
     int n = 7;
     int arr[7] = {7, 6, 5, 4, 3, 2, 1};
     for (int i = 0; i < n; i++)
     {
          struct node *temp = (struct node *)malloc(sizeof(struct node));
          temp->d = arr[i];
          temp->l = temp->r = temp->p = NULL;
          temp->c = 1;
          root = bst(root, temp);
          fixup(root, temp);
          root->c = 0;
     }
     printf("Inorder Traversal of Created Tree\n");
     inorder(root);
     printf("\n the root is %d", root->d);
     return 0;
}