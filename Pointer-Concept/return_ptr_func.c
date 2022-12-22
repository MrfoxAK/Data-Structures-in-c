#include <stdio.h>

int* ptr(int a[]){
     a = a+2;
     return a;
}

int* ptr1(int *a){
     a = a+2;
     return a;
}

int main()
{
     int a[] = {1,2,3,4};
     int * p;
     p = ptr(a);
     int * q;
     q = ptr1(a);
     printf("%d\n",*p);
     printf("%d\n",*ptr(a));
     printf("%d\n",*q);
     printf("%d\n",*ptr1(a));
     printf("%d\n",a[0]);
     return 0;
}