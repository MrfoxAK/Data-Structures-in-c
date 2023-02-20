#include <stdio.h>

int main()
{
     int ele,j=0;
     int arr[] = {10,3,4,78,1,6};
     for (int i = 0; i < 6; i++)
     {
          printf("%d ",arr[i]);
     }
     for (int i = 0; i < 6; i++)
     {
          ele = arr[i];
          j=i-1;
          while (ele<arr[j] && j>=0)
          {
               arr[j+1] = arr[j];
               j--;
          }
          arr[j+1] = ele;
     }
     printf("\n");
     for (int i = 0; i < 6; i++)
     {
          printf("%d ",arr[i]);
     }
     return 0;
}