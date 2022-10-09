
int minValue(struct Node *root)
{
     // your code here
     if (root == NULL)
          return -1;
     struct Node *p = root;
     while (p->left != NULL)
     {
          p = p->left;
     }
     return p->data;
}