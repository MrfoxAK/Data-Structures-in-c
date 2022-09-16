#include <stdio.h>
int main()
{
     int max=0;
     int sum=0;
     int arr[] = {1, -2, 3, -2, 5};
     for (int i = 0; i < 5; i++)
     {
          sum+=arr[i];
          if (sum>max)
          {
               max=sum;
          }
          if (sum<0)
          {
               sum=0;
          }
     }
     printf("%d",max);
     return 0;
}