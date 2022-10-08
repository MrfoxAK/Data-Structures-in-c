#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

void Postorder_traversal(struct node *root)
{
     if (root != NULL)
     {
          Postorder_traversal(root->left);
          Postorder_traversal(root->right);
          printf("%d ", root->data);
     }
}

struct node *create()
{
     int c = 1;
     struct node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));
     printf("Enter data (-1 for blank) : ");
     scanf("%d", &c);
     if (c == -1)
     {
          return 0;
     }
     newnode->data = c;
     printf("Left child of %d : ", c);
     newnode->left = create();
     printf("Right child of %d : ", c);
     newnode->right = create();
     return newnode;
}

int maxDepth(struct node *node)
{
     if (node == NULL)
          return 0;
     else
     {
          /* compute the depth of each subtree */
          int lDepth = maxDepth(node->left);
          int rDepth = maxDepth(node->right);

          /* use the larger one */
          if (lDepth > rDepth)
               return (lDepth + 1);
          else
               return (rDepth + 1);
     }
}

int main()
{
     struct node *root = NULL;
     root = create();
     Postorder_traversal(root);
     printf("The height of the tree is : %d",maxDepth(root));
     return 0;
}