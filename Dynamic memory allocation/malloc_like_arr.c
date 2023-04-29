#include <stdio.h>
#include <stdlib.h>

int main()
{
     int a;
     int * p;
     p = (int*)malloc(sizeof(int));
     *p = 10;
     printf("At address (%x) in heap the value is: %d\n",p,*p);
     int * arr = (int*)malloc(sizeof(int)*5);
     // *arr = 1;
     // *(arr+1) = 2;
     // *(arr+2) = 3;
     // *(arr+3) = 4;
     // *(arr+4) = 5;
     // same as
     arr[0] = 1;
     arr[1] = 2;
     arr[2] = 3;
     arr[3] = 4;
     arr[4] = 5;
     printf("The value of arr[%d] is : %d\n",0,*arr);
     printf("The value of arr[%d] is : %d\n",1,*(arr+1));
     printf("The value of arr[%d] is : %d\n",2,*(arr+2));
     printf("The value of arr[%d] is : %d\n",3,*(arr+3));
     printf("The value of arr[%d] is : %d\n",4,*(arr+4));
     return 0;
}