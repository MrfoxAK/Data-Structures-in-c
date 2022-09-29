#include <stdio.h>

int kadane(int arr1[], int n);

int SumOfMaxcircular(int arr[],int n){
     int maxKadaneSum = kadane(arr,n);
     int max=0;
     for (int i = 0; i < n; i++)
     {
          max += arr[i];
          arr[i] = -arr[i];
     }
     max+=kadane(arr,n);
     return (max>maxKadaneSum)?max : maxKadaneSum;
}

int kadane(int arr1[], int n)
{
     int maxUpto = 0, maxAtPos = 0;
     int i;
     for (i = 0; i < n; i++)
     {
          maxAtPos = maxAtPos + arr1[i];
          if (maxAtPos < 0)
               maxAtPos = 0;
          if (maxUpto < maxAtPos)
               maxUpto = maxAtPos;
     }
     return maxUpto;
}

int main()
{
     int arr[] = {11, 10, -20, 5, -3, -5, 8, -13, 10};
     printf("The sum is %d",SumOfMaxcircular(arr,9));
     return 0;
}