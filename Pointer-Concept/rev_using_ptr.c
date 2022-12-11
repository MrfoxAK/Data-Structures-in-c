#include <stdio.h>

void swap(int *a,int *b){
     int c;
     c=*a;
     *a=*b;
     *b=c;
}

int main()
{
     int a =10;
     int b =20;
     printf("a is %d\nb is %d\n",a,b);
     swap(&a,&b);
     printf("a is %d\nb is %d\n",a,b);
     return 0;
}