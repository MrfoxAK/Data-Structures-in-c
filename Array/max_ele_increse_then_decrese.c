#include <stdio.h>
int main()
{
     int max=0;
     int arr[] = {2, 7, 12, 25, 4, 57, 27, 44};
     for (int i = 0; i < 8; i++)
     {
          if (arr[i]<arr[i+1] && arr[i+1]>arr[i+2] && arr[i+1]>max)
          {
               max=arr[i+1];
          }
     }
     printf("The max is %d",max);
     return 0;
}