#include <stdio.h>
int main()
{
     int arr[] = {1,2,3,-2,5};
     int n = 5;
     int curr_sum=0,max_sum=-111;
     for (int i = 0; i < n; i++)
     {
          curr_sum += arr[i];
          if(curr_sum>max_sum){
               max_sum = curr_sum;
          }
          if(curr_sum<0){
               curr_sum = 0;
          }
     }
     printf("The Max sum is %d",max_sum);
     return 0;
}