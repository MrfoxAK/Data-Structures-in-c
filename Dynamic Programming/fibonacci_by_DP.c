#include <stdio.h>
int main()
{
     int n;
     printf("Enter The Num : ");
     scanf("%d",&n);
     int arr[n];
     arr[0] = 0;
     arr[1] = 1;
     for (int i = 2; i <= n; i++)
     {
          arr[i] = arr[i-1] + arr[i-2];
     }
     // printf("The Fibonacci Num is : %d\n",arr[n]);
     printf("The Fibonacci Series upto %d is below....\n",n);
     for (int i = 0; i <= n; i++)
     {
          printf("%d ",arr[i]);
     }
     return 0;
}