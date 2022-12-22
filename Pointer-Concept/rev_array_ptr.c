#include <stdio.h>
int main()
{
     int arr[] = {1,2,34,5,78,90};
     int *p = arr;
     // printf("%d",(*(p+1)));
     int i=0,temp;
     while (i!=3)
     {
          temp = *(p+i);
          *(p+i) = *(p+5-i);
          *(p+5-i) = temp;
          i++;
     }
     for (int i = 0; i < 6; i++)
     {
          printf("%d ",arr[i]);
     }
     return 0;
}