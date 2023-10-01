#include <stdio.h>
#define r 4
#define c 4

int main()
{
     int matrix[r][c] = {{1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 10, 11, 12},
                       {13, 14, 15,16}};

     int i = 0, j = 0;
     while (j != c-1)
     {
          printf("%d ",matrix[i][j]);
          j++;
     }
     while (i != r-1)
     {
          printf("%d ",matrix[i][j]);
          i++;
     }
     while (j != 0)
     {
          printf("%d ",matrix[i][j]);
          j--;
     }
     while (i != 0)
     {
          printf("%d ",matrix[i][j]);
          i--;
     }
     
     return 0;
}