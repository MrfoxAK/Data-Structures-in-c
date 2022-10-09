#include <stdio.h>

int func1(int n){
     if (n<=1)
     {
          return 1;
     }
     else{
          return n*func2(n-1);
     }
}

int func2(int n){
     if (n<=1)
     {
          return 1;
     }
     else{
          return n*func1(n-1);
     }
}

int main()
{
     printf("%d",func1(5));
     return 0;
}