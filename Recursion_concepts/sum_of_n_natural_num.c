#include <stdio.h>

int sum_of_n(int n){
     int sum=0;
     if (n==0)
     {
          return 0;
     }
     return n + sum_of_n(n-1);
}

int main()
{
     int n=5;
     printf("%d",sum_of_n(n));
     return 0;
}