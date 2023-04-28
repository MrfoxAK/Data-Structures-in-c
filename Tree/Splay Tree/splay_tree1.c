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
     node *n = (node*)malloc(sizeof(node));
     n->data = data;
     n->parent = NULL;
     n->right = NULL;
     n->left = NULL;
     return n;
}

void right_rotate(struct node *temp)
{
     struct node *left = temp->left;
     temp->left = left->right;
     if (temp->left)
          temp->left->parent = temp;
     left->parent = temp->parent;
     if (!temp->parent)
          root = left;
     else if (temp == temp->parent->left)
          temp->parent->left = left;
     else
          temp->parent->right = left;
     left->right = temp;
     temp->parent = left;
}

void left_rotate(struct node *temp)
{
     struct node *right = temp->right;
     temp->right = right->left;
     if (temp->right)
          temp->right->parent = temp;
     right->parent = temp->parent;
     if (!temp->parent)
          root = right;
     else if (temp == temp->parent->left)
          temp->parent->left = right;
     else
          temp->parent->right = right;
     right->left = temp;
     temp->parent = right;
}

void splay(node * root, node *pt)
{
     node* parent_pt = NULL;
     node* grand_parent_pt = NULL;
     while (pt->parent!=NULL)
     {
          if(pt->parent == root){
               if(pt==pt->parent->left){
                    right_rotate(pt->parent);
               }
               else{
                    left_rotate(pt->parent);
               }
          }
          else{
               node *p = pt->parent;
               node *g = p->parent;
               if (pt->parent->left == pt && p->parent->left == p)
               {
                    right_rotate(g);
                    right_rotate(p);
               }
               else if (pt->parent->right == pt && p->parent->right == p)
               {
                    left_rotate(g);
                    left_rotate(p);
               }
               else if (pt->parent->right == pt && p->parent->left == p)
               {
                    left_rotate(p);
                    right_rotate(g);
               }
               else if (pt->parent->left == pt && p->parent->right == p)
               {
                    right_rotate(p);
                    left_rotate(g);
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
     // printf("\nroot %d",root->left->left->left->data);
     return 0;
}