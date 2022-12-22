#include <stdio.h>

int sum(int a,int b){
     return a+b;
}

int * funct(int a, int b);
// here the () have the more precidence the *

int main()
{
     int s;
     int (*func)(int a,int b) = &sum;
     // but here same precidence so associativity is high at first
     s = (*func)(2,3);
     printf("%d ",s);
     return 0;
}