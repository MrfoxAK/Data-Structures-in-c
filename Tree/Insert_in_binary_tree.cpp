#include <iostream>
#include <queue>
using namespace std;

struct node
{
     int data;
     node *left;
     node *right;
};

node *createNewNode(int data)
{
     node *newNode = new node();
     if (!newNode)
     {
          cout << "Memory error\n";
     }
     newNode->data = data;
     newNode->left = newNode->right = NULL;
     return newNode;
}

node *insert(node *root, int data)
{
     if (root == NULL)
     {
          root = createNewNode(data);
          return root;
     }
     queue<node *> q;
     q.push(root);
     while (!q.empty())
     {
          node *temp = q.front();
          q.pop();
          if (temp->left != NULL)
          {
               q.push(temp->left);
          }
          else
          {
               temp->left = createNewNode(data);
               return root;
          }
          if (temp->right != NULL)
               q.push(temp->right);
          else
          {
               temp->right = createNewNode(data);
               return root;
          }
     }
}

void inorder(node *temp)
{
     if (temp == NULL)
          return;

     inorder(temp->left);
     cout << temp->data << ' ';
     inorder(temp->right);
}

int main()
{
     node *root = NULL;
     root = insert(root, 1);
     root = insert(root, 2);
     root = insert(root, 3);
     root = insert(root, 4);
     root = insert(root, 5);
     inorder(root);
     return 0;
}