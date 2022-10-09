#include <stdio.h>

int display(int n){
     if (n<1)
     {
          return 0;
     }
     else
     {
          printf("%d ",n);
          display(n-1);
          printf("%d ",n);
     }
}

int main()
{
     int n=4;
     display(n);
     return 0;
}