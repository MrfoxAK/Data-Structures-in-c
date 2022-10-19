#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

struct node *createNode(int data)
{
     struct node *node;
     node = (struct node *)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     return node;
}

void Postorder_traversal(struct node *root)
{
     if (root != NULL)
     {
          Postorder_traversal(root->left);
          Postorder_traversal(root->right);
          printf("%d ", root->data);
     }
}

// Calculate the depth
int depth(struct node *node)
{
     int d = 0;
     while (node != NULL)
     {
          d++;
          node = node->left;
     }
     return d;
}

int Check_Perfect_BT(struct node *root,int d,int level)
{
     if (root == NULL)
          return 1;
     
}

int main()
{

     // using function
     struct node *p = createNode(4);
     struct node *p1 = createNode(1);
     struct node *p2 = createNode(6);
     struct node *p3 = createNode(5);
     struct node *p4 = createNode(2);

     p->left = p1;
     p->right = p2;
     p1->left = p3;
     p1->right = p4;

     Postorder_traversal(p);
     printf("\n%d", Check_Perfect_BT(p));
     return 0;
}