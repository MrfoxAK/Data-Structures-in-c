#include <stdio.h>
#include <stdlib.h>

int main()
{
     int a;
     int * p;
     p = (int*)malloc(sizeof(int));
     *p = 10;
     // printf("At address (%x) in heap the value is: %d\n",p,*p);
     int * p1 = (int*)malloc(sizeof(int)*5);
     *(p1+1) = 1;
     printf("%d ",*(p1+1));
     p1[0] = 0;
     printf("%d ",*(p1));
}