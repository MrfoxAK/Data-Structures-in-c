#include <stdio.h>
int main()
{
     int count=0,index;
     int arr[] = { 6, 0, 8, 2, 3, 0, 4, 0, 1 };
     for (int i = 0; i < 9; i++)
     {
          if (arr[i]==0)
          {
               index=i;
               count++;
               for (int j = index; j < 9; j++)
               {
                    arr[j] = arr[j+1];
               }
          }
     }
     while (count)
     {
          arr[9-count] = 0;
          count--;
     }
     for (int i = 0; i < 9; i++)
     {
          printf("%d ",arr[i]);
     }
     
     return 0;
}