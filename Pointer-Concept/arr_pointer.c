#include <stdio.h>
int main()
{
     int arr[10];
     int * ptr  = arr;
     printf("Enter array: ");
     for (int i = 0; i < 10; i++)
     {
          scanf("%d",ptr);
          ptr++;
     }
     ptr=arr;
     printf("Array elements: ");
     for (int i = 0; i < 10; i++)
     {
          printf("%d ",*ptr);
          ptr++;
     }
     return 0;
}