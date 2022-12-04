#include <stdio.h>
int main()
{
     int arr[] = {1,2,3};
     int arr2[] = {1,2,3};
     int marr[6];
     int i=0,j=0,k=0;
     while (i<3 && j<3)
     {
          if (arr[i]<arr2[j])
          {
               marr[k] = arr[i];
               k++;
               i++;
          }
          else
          {
               marr[k] = arr2[j];
               k++;
               j++;    
          }
     }
     while (i<3)
     {
          marr[k] = arr[i];
          i++;
          k++;
     }
     while (j<3)
     {
          marr[k] = arr2[j];
          j++;
          k++;
     }
     for (int z= 0; z< 6; z++)
     {
          printf("%d ",marr[z]);
     }
     return 0;
}