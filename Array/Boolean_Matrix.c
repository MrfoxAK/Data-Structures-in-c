#include <stdio.h>

struct node
{
     int row;
     int col;
};

void booleanMatrix(int r, int c, int matrix[r][c]){
     int max_ele_possible = r*c;
     struct node m[max_ele_possible];
     int count = 0;
     // int arr[max_ele_possible];
     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               if(matrix[i][j] == 1){
                    m[count].row = i;
                    m[count].col = j;
                    count++;
               }
          }
     }
     // The add 1 part
     for (int i = 0; i < count; i++)
     {
          for (int j = 0; j < r; j++)
          {
               matrix[j][m[i].col] = 1;
          }
          for (int j = 0; j < c; j++)
          {
               matrix[m[i].row][j] = 1;
          }
     }
}

int main()
{
     int r=3,c=4;
     int matrix[r][c];
     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               scanf("%d",&matrix[i][j]);
          }
     }
     booleanMatrix(r,c,matrix);
     for (int i = 0; i < r; i++)
     {
          for (int j = 0; j < c; j++)
          {
               printf("%d ",matrix[i][j]);
          }
          printf("\n");
     }
     return 0;
}