#include <stdio.h>
#include <limits.h>

#define V 5

int minKey(int a[],int checked[]){
     int min=INT_MAX;
     int i;
     for (i = 0; i < V; i++)
     {
          if(min>a[i] && checked[i]==0)
               min = i;
     }
     return min;
}

void primMST(int graph[V][V]){
     int A[V];
     int checked[V];
     int mst[V];
     for (int i = 0; i < V; i++)
     {
          A[i] = INT_MAX;
          checked[i] = 0;
     }
     A[0] = 0;
     for (int i = 0; i < V; i++)
     {
          int u = minKey(A,checked);
          printf("\n----%d-----\n",u);
          checked[u] = 1;
          int min=INT_MAX;
          int j;
          for (j = 0; j < V; j++)
          {
               if(graph[u][j]<min && graph[u][j]!=0)
                    min = graph[u][j];
          }
          printf("%d ",min);
          A[j] = min;
     }
}

int main()
{
     int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
     primMST(graph);
     return 0;
}