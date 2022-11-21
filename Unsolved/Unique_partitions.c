#include <stdio.h>

void Unique_partition(int n){
     int n1 = n;
     for (int i = 0; i < n; i++)
     {
          if (i = n/2)
          {
               Unique_partition(i);
          }
          if (i + n1-i == n)
          {
               printf("%d %d\n",n-i,i);
               n1 -= 1;
          }
     }
}

int main()
{
     int n;
     printf("Enter the Num : ");
     scanf("%d",&n);
     Unique_partition(n);
     return 0;
}