#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
         {0, 1, 1, 1, 0, 0, 0},
         {1, 0, 0, 1, 0, 0, 0},
         {1, 1, 0, 1, 1, 0, 0},
         {1, 0, 1, 0, 1, 0, 0},
         {0, 0, 1, 1, 0, 1, 1},
         {0, 0, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 1, 0, 0}};

void DFS(int data){
     printf("%d ",data);
     visited[data] = 1;
     for (int i = 0; i < 7; i++)
     {
          if(visited[i]==0 && a[data][i] == 1){
               DFS(i);
          }
     }
}

int main()
{
     DFS(0);
     return 0;
}