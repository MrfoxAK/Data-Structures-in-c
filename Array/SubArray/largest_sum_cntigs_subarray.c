#include <stdio.h>
int main()
{
     int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
     int n = 8;
     int currSum=0,maxSum=0;
     for (int i = 0; i < n; i++)
     {
          currSum = currSum+arr[i];
          if(currSum>maxSum){
               maxSum = currSum;
          }
          if(currSum < 0){
               currSum = 0;
          }
     }
     printf("The longest Sum is : %d\n",maxSum);
     return 0;
}