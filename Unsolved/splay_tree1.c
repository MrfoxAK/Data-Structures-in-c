#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
     int data;
     struct node *left;
     struct node *right;
     struct node *parent;
} node;

node *root = NULL;

node *new_node(int data)
{
     node *n = malloc(sizeof(node));
     n->data = data;
     n->parent = NULL;
     n->right = NULL;
     n->left = NULL;
     return n;
}

void left_rotate(node* t, node *x)
{
     node *y = x->right;
     x->right = y->left;
     if (y->left != NULL)
     {
          y->left->parent = x;
     }
     y->parent = x->parent;
     if (x->parent == NULL)
     { // x is root
          t = y;
     }
     else if (x == x->parent->left)
     { // x is left child
          x->parent->left = y;
     }
     else
     { // x is right child
          x->parent->right = y;
     }
     y->left = x;
     x->parent = y;
}

void right_rotate(node * t, node *x)
{
     node *y = x->left;
     x->left = y->right;
     if (y->right != NULL)
     {
          y->right->parent = x;
     }
     y->parent = x->parent;
     if (x->parent == NULL)
     { // x is root
          t = y;
     }
     else if (x == x->parent->right)
     { // x is left child
          x->parent->right = y;
     }
     else
     { // x is right child
          x->parent->left = y;
     }
     y->right = x;
     x->parent = y;
}

void splay(node * root, node *pt)
{
     node* parent_pt = NULL;
     node* grand_parent_pt = NULL;
     while (pt->parent!=NULL)
     {
          if(pt->parent == root){
               if(pt==pt->parent->left)
                    right_rotate(root,pt->parent);
               else
                    left_rotate(root,pt->parent);
          }
          else{
               parent_pt = pt->parent;
               grand_parent_pt = parent_pt->parent;
               if(parent_pt==grand_parent_pt->left && parent_pt->left == pt){
                    right_rotate(root,grand_parent_pt);
                    right_rotate(root,parent_pt);
               }
               else if(parent_pt==grand_parent_pt->left && parent_pt->right == pt){
                    left_rotate(root,parent_pt);
                    right_rotate(root,grand_parent_pt);
               }
               else if (parent_pt==grand_parent_pt->right && parent_pt->right == pt)
               {
                    left_rotate(root, grand_parent_pt);
                    left_rotate(root, parent_pt);
               }
               else if (parent_pt==grand_parent_pt->right && parent_pt->left == pt)
               {
                    right_rotate(root, parent_pt);
                    left_rotate(root, grand_parent_pt);
               }
          }
     }
}

struct node *bst(struct node *trav, struct node *temp)
{
     if (trav == NULL)
          return temp;
     if (temp->data < trav->data)
     {
          trav->left = bst(trav->left, temp);
          trav->left->parent = trav;
     }
     else if (temp->data > trav->data)
     {
          trav->right = bst(trav->right, temp);
          trav->right->parent = trav;
     }
     return trav;
}

void inorder(node *root)
{
     if (root == NULL)
          return;
     inorder(root->left);
     printf("%d ", root->data);
     inorder(root->right);
}

int main()
{
     int n = 13;
     int a[] = {10, 20, 30, 100, 90, 40, 50, 60, 70, 80, 150, 110, 120};
     for (int i = 0; i < n; i++)
     {
          struct node *temp = (struct node *)malloc(sizeof(struct node));
          temp->right = NULL;
          temp->left = NULL;
          temp->parent = NULL;
          temp->data = a[i];
          root = bst(root, temp);
          splay(root, temp);
     }
     printf("Inorder Traversal of Created Tree\n");
     inorder(root);
     return 0;
}