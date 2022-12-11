#include <stdio.h>
int main()
{
     // int a = 10;
     // int * p = &a;
     // int ** q = &p;
     // int *** r = &q;
     // printf("%d ",a);
     // printf("%u ",p);
     // // printf("%u ",q);
     // // printf("%d ",*p);
     // printf("%d ",*q);
     // printf("%d ",**q);
     // printf("%d ",***r);
     // addition
     // printf("%d ",p);
     // printf("%d ",p+1);
     // printf("dereference %d ",*p+1);
     // printf("%d ",*(p+1)); //it will give a garvage value
     // printf("%d ",p+2);
     int arr[10] = {1,21,31,24,25};
     int * p = arr;
     p=p+2;
     printf("%u\n",*p+1);
     printf("%u\n",*(p+1));
     // for loop write - printf("%u\n",*(p+i));
     return 0;
}