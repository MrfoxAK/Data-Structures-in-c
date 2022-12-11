#include <stdio.h>

void swap(int arr[],int *a,int *b){
     int c;
     c=*a;
     *a=*b;
     *b=c;
     for (int i = 0; i < 5; i++)
     {
          arr[i] = 0;
     }
}

int main()
{
     int arr[] = {1,2,3,4,5};
     int a =10;
     int b =20;
     printf("a is %d\nb is %d\n",a,b);
     for (int i = 0; i < 5; i++)
     {
          printf("%d ",arr[i]);
     }
     swap(arr,&a,&b);
     printf("\na is %d\nb is %d\n",a,b);
     for (int i = 0; i < 5; i++)
     {
          printf("%d ",arr[i]);
     }
     // a,b is local variable is so its passed a arguments 
     // so it's never change untill it's passed as address
     // but for array it is passed the based address of it's 1st elements 
     // so that it's change 
     return 0;
}