#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
     struct node *parent;
};

struct splay_tree
{
     struct node *root;
};

struct node *new_node(int data)
{
     struct node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));
     newnode->data = data;
     newnode->left = NULL;
     newnode->right = NULL;
     return newnode;
}

struct splay_tree *new_splay_tree()
{
     struct splay_tree *t = (struct splay_tree *)malloc(sizeof(struct splay_tree));
     t->root = NULL;
     return t;
}

void insert(struct splay_tree *t, struct node *n)
{
     struct node *y = NULL;
     struct node *temp = t->root;
     while (temp != NULL)
     {
          y = temp;
          if (n->data < temp->data)
               temp = temp->left;
          else
               temp = temp->right;
     }
     n->parent = y;
     if (y == NULL)
     {
          t->root = n;
     }
     else if (n->data < y->data)
     {
          y->left = n;
     }
     else
     {
          y->right = n;
     }
}

void inorder(struct splay_tree *t,struct node *n)
{
     if (n != NULL)
     {
          inorder(t, n->left);
          printf("%d\n", n->data);
          inorder(t, n->right);
     }
}

int main()
{
     struct splay_tree *t = new_splay_tree();

     struct node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;
     a = new_node(10);
     b = new_node(20);
     c = new_node(30);
     d = new_node(100);
     e = new_node(90);
     f = new_node(40);
     g = new_node(50);
     h = new_node(60);
     i = new_node(70);
     j = new_node(80);
     k = new_node(150);
     l = new_node(110);
     m = new_node(120);

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

     // delete (t, a);
     // delete (t, m);

     inorder(t, t->root);

     return 0;
     return 0;
}