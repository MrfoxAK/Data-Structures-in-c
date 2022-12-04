#include <stdio.h>
int main()
{
     int arr1[] = {1,2,3};
     int arr2[] = {1,2,3};
     int arr3[6];
     int i=0,j=0,z=0;
     while (i<3 && j<3)
     {
          if (arr1[i]<arr2[j])
          {
               arr3[z] = arr1[i];
               z++;
               i++;
          }
          else
          {
               arr3[z] = arr2[j];
               z++;
               j++;
          }
     }
     while (i<3)
     {
          arr3[z] = arr1[i];
          z++;
          i++;
     }
     while (j<3)
     {
          arr3[z] = arr2[j];
          z++;
          j++;
     }
     for (int k = 0; k < 6; k++)
     {
          printf("%d ",arr3[k]);
     }
     
     return 0;
}