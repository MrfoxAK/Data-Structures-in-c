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
     int one[3],sec[3],thrid[3],four[4];
     int c1=0,c2=0,c3=0,c4=0;
     int t = 3*4;
     int total[t];
     while (j != c-1)
     {
          // printf("%d ",matrix[i][j]);
          one[c1] = matrix[i][j];
          c1++;
          // printf("%d ",matrix[c-1][c-j-1]);
          thrid[c3] = matrix[c-1][c-j-1];
          c3++;
          j++;
     }
     while (i != r-1)
     {
          // printf("%d ",matrix[i][j]);
          sec[c2] = matrix[i][j];
          c2++;
          // printf("%d ",matrix[c-i-1][0]);
          four[c4] = matrix[c-i-1][0];
          c4++;
          i++;
     }
     int t1=0;
     while (t1 != t)
     {
          for (int i = 0; i < 3; i++)
          {
               total[t1] = one[i];
               t1++;
          }
          for (int i = 0; i < 3; i++)
          {
               total[t1] = sec[i];
               t1++;
          }
          for (int i = 0; i < 3; i++)
          {
               total[t1] = thrid[i];
               t1++;
          }
          for (int i = 0; i < 3; i++)
          {
               total[t1] = four[i];
               t1++;
          }
     }
     for (int i = 0; i < t; i++)
     {
          printf("%d ",total[i]);
     }
     return 0;
}