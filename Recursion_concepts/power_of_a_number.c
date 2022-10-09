#include <stdio.h>

int power(int n,int n1){
     if (n1==0)
     {
          return 1;
     }
     return n * power(n,n1-1);
}

int main()
{
     int num;
     printf("%d",power(2,5));
     return 0;
}