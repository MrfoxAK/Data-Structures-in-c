#include <stdio.h>

int subarray(int arr[],int n){
     int sum=0;
     for (int i = 0; i < n; i++)
     {
          sum=0;
          for (int j = i; j < n; j++)
          {
               sum+=arr[j];
               if (sum==0)
               {
                    return 1;
               }
          }
     }
     return 0;
}

int main()
{
     int sum=0;
     int arr[]= { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
     printf("%d",subarray(arr,10));
     return 0;
}