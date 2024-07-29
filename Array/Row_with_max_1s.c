#include <stdio.h>
#define row 4
#define col 4

int main()
{
     int max_index=row;
     int max=0;
     int curr_total = 0;
     int arr[row][col] = {{0, 1, 1, 1},
                         {0, 0, 1, 1},
                         {1, 1, 1, 1},
                         {0, 0, 0, 0}};
     for (int i = 0; i < row; i++)
     {
          curr_total=0;
          for (int j = col-1; j >= 0; j--)
          {
               if (arr[i][j] == 1)
               {
                    curr_total++;
               }
          }
          if (curr_total>max)
          {
               max = curr_total;
               max_index = i;
          }
     }
     printf("The Index is %d\n",max_index);
     return 0;
}