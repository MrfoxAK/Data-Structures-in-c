#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
     int data;
     struct Node *left;
     struct Node *right;
} Node;

Node *createNode(int data)
{
     Node *node = (Node *)malloc(sizeof(Node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     return node;
}

Node *rightRotate(Node *x)
{
     Node *y = x->left;
     x->left = y->right;
     y->right = x;
     return y;
}

Node *leftRotate(Node *x)
{
     Node *y = x->right;
     x->right = y->left;
     y->left = x;
     return y;
}

Node *splay(Node *root, int key)
{
     if (root == NULL || root->data == key)
     {
          return root;
     }

     // Key lies in the left subtree
     if (key < root->data)
     {
          if (root->left == NULL)
               return root;

          // Zig-Zig (Left Left)
          if (key < root->left->data)
          {
               root->left->left = splay(root->left->left, key);
               root = rightRotate(root);
          }
          // Zig-Zag (Left Right)
          else if (key > root->left->data)
          {
               root->left->right = splay(root->left->right, key);
               if (root->left->right != NULL)
               {
                    root->left = leftRotate(root->left);
               }
          }

          return (root->left == NULL) ? root : rightRotate(root);
     }
     // Key lies in the right subtree
     else
     {
          if (root->right == NULL)
               return root;

          // Zag-Zig (Right Left)
          if (key < root->right->data)
          {
               root->right->left = splay(root->right->left, key);
               if (root->right->left != NULL)
               {
                    root->right = rightRotate(root->right);
               }
          }
          // Zag-Zag (Right Right)
          else if (key > root->right->data)
          {
               root->right->right = splay(root->right->right, key);
               root = leftRotate(root);
          }

          return (root->right == NULL) ? root : leftRotate(root);
     }
}

Node *insertNode(Node *root, int key)
{
     if (root == NULL)
          return createNode(key);

     root = splay(root, key);

     if (root->data == key)
          return root;

     Node *newNode = createNode(key);

     if (key < root->data)
     {
          newNode->right = root;
          newNode->left = root->left;
          root->left = NULL;
     }
     else
     {
          newNode->left = root;
          newNode->right = root->right;
          root->right = NULL;
     }

     return newNode;
}

void inorderTraversal(Node *root)
{
     if (root != NULL)
     {
          inorderTraversal(root->left);
          printf("%d ", root->data);
          inorderTraversal(root->right);
     }
}

int main()
{
     Node *root = NULL;

     root = insertNode(root, 10);
     root = insertNode(root, 20);
     root = insertNode(root, 30);
     root = insertNode(root, 40);
     root = insertNode(root, 50);
     root = insertNode(root, 25);

     printf("Inorder Traversal of Created Tree\n");
     inorderTraversal(root);
     printf("\nThe root is %d\n",root->data);
     return 0;
}
