#include <stdio.h>

int main()
{
     int n = 5;
     int arr[] = {6,9,5,1,8};
     for (int i = 0; i < n; i++)
     {
          int element = arr[i];
          int j = i-1;
          while (j > -1 && arr[j] > element)
          {
               arr[j+1] = arr[j];
               j--;
          }
          arr[j + 1] = element;
     }
     for (int i = 0; i < n; i++)
     {
          printf("%d ",arr[i]);
     }
     return 0;
}