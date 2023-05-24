#include <stdio.h>
#include <stdlib.h>
#define MAX 3
#define MIN 2

struct node
{
     int val[MAX + 1], count;
     struct node *link[MAX + 1];
};

struct node *root = NULL;

struct node* createNode(int val, struct node* child){
     struct node* newNode;
     newNode = (struct node*)malloc(sizeof(struct node));
     newNode->val[1] = val;
     newNode->count = 1;
     newNode->link[0] = root;
     newNode->link[1] = child;
     return newNode;
}

void insertNode(int val,int pos,struct node* n,struct node* child){
     int j = n->count;
     while (j > pos)
     {
          
          j--;
     }
     
}

int setValue(int val, int *pval, struct node *n, struct node **child)
{
     int pos;
     if (!n)
     {
          *pval = val;
          *child = NULL;
          return 1;
     }
     if (val < n->val[1])
     {
          pos = 0;
     }
     else
     {
          for (pos = n->count; (val < n->val[pos] && pos > 1); pos--)
               ;
          if (val == n->val[pos])
          {
               printf("Duplicates are not permitted\n");
               return 0;
          }
     }
     if (setValue(val, pval, n->link[pos], child))
     {
          if (n->count < MAX)
          {
               insertNode(*pval, pos, n, *child);
          }
          else
          {
               splitNode(*pval, pval, pos, n, *child, child);
               return 1;
          }
     }
     return 0;
}

void insert(int val)
{
     int i, flag;
     struct node *child;
     flag = setValue(val, &i, root, &child);
     if(flag)
          root = createNode(i,child);
}

int main()
{
     int val, ch;
     insert(8);
     return 0;
}