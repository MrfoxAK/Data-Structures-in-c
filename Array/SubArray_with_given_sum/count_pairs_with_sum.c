#include <stdio.h>
int main()
{
     int arr[] = {1, 5, 7, 1};
     int k = 6;
     int count=0;
     for (int i = 0; i < 4; i++)
     {
          for (int j = i+1; j < 4; j++)
          {
               if (arr[i]+arr[j]==k)
               {
                    count++;
                    printf("%d,%d\n",arr[i],arr[j]);
               }
          }
     }
     printf("Total is %d",count);
     return 0;
}