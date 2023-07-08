#include <stdio.h>
#include <stdlib.h>

struct node
{
     int v;
     int w;
};

int size;

struct node* newNode(int v,int w)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->v = v;
     node->w = w;
	return (node);
}

struct node **PQueue()
{
     struct node **pq = (struct node **)malloc(sizeof(struct node *) * 500);
     size = 0;
     return pq;
}

void insert(struct node **q, struct node* n)
{
     size++;
     int i = size;
     q[i] = n;
     while (i > 1)
     {
          int parent = i / 2;
          if (q[parent]->w > q[i]->w)
          {
               struct node* temp = q[parent];
               q[parent] = q[i];
               q[i] = temp;
               i = parent;
          }
          else{
               return;
          }
     }
}

int main()
{
     struct node **q = PQueue();
     insert(q,newNode(0,50));
     insert(q,newNode(1,55));
     insert(q,newNode(2,53));
     insert(q,newNode(3,52));
     insert(q,newNode(4,54));
     printf("%d,%d\n",q[1]->v,q[1]->w);
     printf("%d,%d\n",q[2]->v,q[2]->w);
     printf("%d,%d\n",q[3]->v,q[3]->w);
     printf("%d,%d\n",q[4]->v,q[4]->w);
     printf("%d,%d\n",q[5]->v,q[5]->w);
     return 0;
}