#include <stdio.h>
int main()
{
     int r1, r2, c1, c2;
     int a[50][50], b[50][50], c[50][500];
     int *pa, *pb, *pc;
     pa = &a[0][0];
     pb = &b[0][0];
     pc = &c[0][0];
     // 1st input
     printf("Enter the 1st matrix row and coloms : ");
     scanf("%d%d", &r1, &c1);
     for (int i = 0; i < c1; i++)
     {
          for (int j = 0; j < r1; j++)
          {
               printf("Enter element at a[%d][%d]: ", i, j);
               scanf("%d", (*(a + i) + j));
          }
     }
     // 2nd input
     printf("Enter the 2nd matrix row and coloms : ");
     scanf("%d%d", &r2, &c2);
     for (int i = 0; i < c2; i++)
     {
          for (int j = 0; j < r2; j++)
          {
               printf("Enter element at b[%d][%d]: ", i, j);
               scanf("%d", (*(b + i) + j));
          }
     }
     // sum
     for (int i = 0; i < c1; i++)
     {
          for (int j = 0; j < r1; j++)
          {
               *(*(c + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
          }
     }
     // print
     printf("The sum matrix is : \n");
     for (int i = 0; i < c1; i++)
     {
          for (int j = 0; j < r1; j++)
          {
               printf("%d ", *(*(c + i) + j));
          }
          printf("\n");
     }
     return 0;
}