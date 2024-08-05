#include <stdio.h>

int minCoins(int n, int arr[], int size){
     int ans = 1000;
     if (n == 0)
     {
          return 0;
     }
     for (int i = 0; i < size; i++)
     {
          if (n - arr[i] >=0)
          {
               int subAns = minCoins(n-arr[i],arr,size);
               if (subAns != 1000 && subAns + 1 < ans)
               {
                    ans = subAns + 1;
               }
          }
     }
     return ans;
}

int main()
{
     int arr[] = {7,5,1};
     printf("The min Coins is : %d",minCoins(18,arr,3));
     return 0;
}