#include <stdio.h>
#include <stdlib.h>

enum COLOR
{
     Red,
     Black
};

typedef struct tree_node
{
     int data;
     struct tree_node *right;
     struct tree_node *left;
     struct tree_node *parent;
     enum COLOR color;
} tree_node;

typedef struct red_black_tree
{
     tree_node *root;
     tree_node *NIL;
} red_black_tree;

tree_node *new_tree_node(int data)
{
     tree_node *n = malloc(sizeof(tree_node));
     n->left = NULL;
     n->right = NULL;
     n->parent = NULL;
     n->data = data;
     n->color = Red;

     return n;
}

red_black_tree *new_red_black_tree()
{
     red_black_tree *t = malloc(sizeof(red_black_tree));
     tree_node *nil_node = malloc(sizeof(tree_node));
     nil_node->left = NULL;
     nil_node->right = NULL;
     nil_node->parent = NULL;
     nil_node->color = Black;
     nil_node->data = 0;
     t->NIL = nil_node;
     t->root = t->NIL;

     return t;
}

void left_rotate(red_black_tree *t, tree_node *x)
{
     tree_node *y = x->right;
     x->right = y->left;
     if (y->left != t->NIL)
     {
          y->left->parent = x;
     }
     y->parent = x->parent;
     if (x->parent == t->NIL)
     { // x is root
          t->root = y;
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

void right_rotate(red_black_tree *t, tree_node *x)
{
     tree_node *y = x->left;
     x->left = y->right;
     if (y->right != t->NIL)
     {
          y->right->parent = x;
     }
     y->parent = x->parent;
     if (x->parent == t->NIL)
     { // x is root
          t->root = y;
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

void insertion_fixup(red_black_tree *root, tree_node *pt)
{
     while (pt->parent->color == Red)
     {
          if (pt->parent == pt->parent->parent->left)
          {
               tree_node *uncle_pt = pt->parent->parent->right;
               if (uncle_pt == Red)
               {
                    uncle_pt->color = Black;
                    pt->parent->color = Black;
                    pt->parent->parent->color = Red;
                    pt = pt->parent->parent;
               }
               else
               {
                    if (pt == pt->parent->right)
                    {
                         pt = pt->parent;
                         left_rotate(root,pt);
                    }
                    else
                    {
                         pt->parent->color = Black;
                         pt->parent->parent->color = Red;
                         right_rotate(root,pt->parent->parent);
                    }
               }
          }
          else
          {
               tree_node *uncle_pt = pt->parent->parent->left;
               if (uncle_pt == Red)
               {
                    uncle_pt->color = Black;
                    pt->parent->color = Black;
                    pt->parent->parent->color = Red;
                    pt = pt->parent->parent;
               }
               else{
                    if(pt == pt->parent->left){
                         pt = pt->parent;
                         right_rotate(root,pt);
                    }
                    else{
                         pt->parent->color = Black;
                         pt->parent->parent->color = Red;
                         left_rotate(root,pt->parent->parent);
                    }
               }
          }
     }
     root->root->color = Black;
}

void insert(red_black_tree *t, tree_node *z)
{
     tree_node *y = t->NIL; // variable for the parent of the added node
     tree_node *temp = t->root;

     while (temp != t->NIL)
     {
          y = temp;
          if (z->data < temp->data)
               temp = temp->left;
          else
               temp = temp->right;
     }
     z->parent = y;

     if (y == t->NIL)
     { // newly added node is root
          t->root = z;
     }
     else if (z->data < y->data) // data of child is less than its parent, left child
          y->left = z;
     else
          y->right = z;

     z->right = t->NIL;
     z->left = t->NIL;

     insertion_fixup(t, z);
}

void inorder(red_black_tree *t, tree_node *n)
{
     if (n != t->NIL)
     {
          inorder(t, n->left);
          printf("%d\n", n->data);
          inorder(t, n->right);
     }
}

int main()
{
     red_black_tree *t = new_red_black_tree();

     tree_node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;
     a = new_tree_node(10);
     b = new_tree_node(20);
     c = new_tree_node(30);
     d = new_tree_node(100);
     e = new_tree_node(90);
     f = new_tree_node(40);
     g = new_tree_node(50);
     h = new_tree_node(60);
     i = new_tree_node(70);
     j = new_tree_node(80);
     k = new_tree_node(150);
     l = new_tree_node(110);
     m = new_tree_node(120);

     insert(t, a);
     insert(t, b);
     insert(t, c);
     insert(t, d);
     insert(t, e);
     insert(t, f);
     insert(t, g);
     insert(t, h);
     insert(t, i);
     insert(t, j);
     insert(t, k);
     insert(t, l);
     insert(t, m);

     inorder(t, t->root);

     return 0;
}