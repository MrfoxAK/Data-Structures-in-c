#include <stdio.h>
int main()
{
     int max=0;
     int arr[] = {3,1,9,7,1,2,4};

     for (int i = 0; i < 7; i++)
     {
          if (arr[i]>max)
          {
               max=arr[i];
          }
     }

     // printf("%d",max);
     int carr[max+1];
     for (int i = 0; i < max+1; i++)
     {
          carr[i]=0;
     }

     for (int i = 0; i < 7; i++)
     {
          carr[arr[i]]++;
     }

     // for check
     // for (int i = 0; i < max+1; i++)
     // {
     //      printf("%d ",carr[i]);
     // }
     // printf("\n");
     // global
     int j=0;
     int arr2[7];
     for (int i = 0; i < max+1;)
     {
          if (carr[i]>0)
          {
               arr2[j]=i;
               carr[i]--;
               j++;
          }
          else
          {
               i++;
          }
     }
     for (int i = 0; i < 7; i++)
     {
          printf("%d ",arr2[i]);
     }
     return 0;
}