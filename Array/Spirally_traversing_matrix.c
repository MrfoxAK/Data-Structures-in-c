#include <stdio.h>
#define row 4
#define col 4

int main()
{
     int A[row][col] = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};
     int T, B, L, R, dir;
     T = 0;
     B = row - 1;
     L = 0;
     R = col - 1;
     dir = 0;
     int i;
     while (T <= B && L <= R)
     {
          if (dir == 0)
          {
               for (i = L; i <= R; i++)
                    printf("%d ",(A[T][i]));
               T++;
          }
          else if (dir == 1)
          {
               for (i = T; i <= B; i++)
                    printf("%d ",(A[i][R]));
               R--;
          }
          else if (dir == 2)
          {
               for (i = R; i >= L; i--)
                    printf("%d ",(A[B][i]));
               B--;
          }
          else if (dir == 3)
          {
               for (i = B; i >= T; i--)
                    printf("%d ",(A[i][L]));
               L++;
          }
          dir = (dir + 1) % 4;
     }
     return 0;
}