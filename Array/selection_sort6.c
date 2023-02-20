#include <stdio.h>
int main()
{
     int arr[] = {4,2,5,45,6,9,65,43};
     int min_index=0,ele,temp;
     for (int i = 0; i <8 ; i++)
     {
          printf("%d ",arr[i]);
     }
     printf("\n");
     for (int i = 0; i < 8; i++)
     {
          // ele = arr[i];
          min_index=i;
          for (int j = i+1; j < 8; j++)
          {
               if (arr[j]<arr[min_index])
               {
                    min_index=j;
               }
          }
          temp = arr[i];
          arr[i] = arr[min_index];
          arr[min_index] = temp;
     }
     for (int i = 0; i <8 ; i++)
     {
          printf("%d ",arr[i]);
     }
     return 0;
}