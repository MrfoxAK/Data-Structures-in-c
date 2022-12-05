#include <stdio.h>
#include <stdlib.h>

struct Node
{
     char data;
     struct Node *right;
     struct Node *left;
};

void enq(struct Node *temproot);
struct Node *deq(void);
struct Node *Insert(struct Node *, char x);
struct Node *newNode(char data);
void LevelOrder(struct Node *root);
void dump_BST(const char *tag, const struct Node *node);

struct Node *front = NULL;
struct Node *rear = NULL;

int main(void)
{
     struct Node *root = NULL;
     dump_BST("Empty", root);
     root = Insert(root, 'F');
     dump_BST("Added F", root);
     root = Insert(root, 'B');
     dump_BST("Added B", root);
     root = Insert(root, 'C');
     // dump_BST("Added C", root);
     root = Insert(root, 'D');
     // dump_BST("Added D", root);
     root = Insert(root, 'E');
     // dump_BST("Added E", root);
     root = Insert(root, 'G');
     // dump_BST("Added G", root);
     root = Insert(root, 'A');
     // dump_BST("Added A", root);
     root = Insert(root, 'H');
     // dump_BST("Added H", root);
     root = Insert(root, 'I');
     dump_BST("Added I", root);
     LevelOrder(root);

     return 0;
}

struct Node *Insert(struct Node *root, char x)
{
     if (root == NULL)
     {
          root = newNode(x);
     }
     else if (x <= root->data)
     {
          root->left = Insert(root->left, x);
     }

     else
     {
          root->right = Insert(root->right, x);
     }
     return root;
}

struct Node *newNode(char x)
{
     struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
     temp1->data = x;
     temp1->right = NULL;
     temp1->left = NULL;
     return temp1;
}

void enq(struct Node *temproot)
{
     struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
     temp->right = NULL;
     temp->left = temproot;
     temp->data = 'Z';

     if (front == NULL && rear == NULL)
     {
          front = rear = temp;
     }
     else
     {
          rear->right = temp;
          rear = temp;
     }
}

struct Node *deq(void)
{
     struct Node *temp = front;
     if (front == NULL)
     {
          printf("The queue is empty!\n");
     }
     else if (rear == front)
     {
          front = rear = NULL;
     }
     else
     {
          front = front->right;
     }
     struct Node *next = (temp == NULL) ? NULL : temp->left;
     free(temp);
     return next;
}

void LevelOrder(struct Node *root)
{
     struct Node *temproot = root;

     while (temproot != NULL)
     {
          printf("%c ", temproot->data);
          if (temproot->left != NULL)
          {
               enq(temproot->left);
          }
          if (temproot->right != NULL)
          {
               enq(temproot->right);
          }
          temproot = deq();
     }
     putchar('\n');
}

static void dump_BST_nodes(const struct Node *node)
{
     if (node != NULL)
     {
          printf("Node: '%c' (ptr = %p, left = %p, right = %p)\n",
                 node->data, (void *)node, (void *)node->left, (void *)node->right);
          dump_BST_nodes(node->left);
          dump_BST_nodes(node->right);
     }
}

void dump_BST(const char *tag, const struct Node *node)
{
     printf("%s:\n", tag);
     dump_BST_nodes(node);
     printf("%s: end\n", tag);
}