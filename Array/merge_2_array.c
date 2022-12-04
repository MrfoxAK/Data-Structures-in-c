#include <stdio.h>
int main()
{
     int a1[100], a2[100], marray[100];
     int i, j, k, z, size1, size2,tsize;
     printf("Enter size of 1st array: ");
     scanf("%d", &size1);
     for (i = 0; i < size1; i++)
     {
          printf("Enter element: ");
          scanf("%d", &a1[i]);
     }
     printf("Enter size of 2nd array: ");
     scanf("%d", &size2);
     for (j = 0; j < size2; j++)
     {
          printf("Enter element: ");
          scanf("%d", &a2[j]);
     }
     tsize=size1+size2;
     i=0,j=0,k=0;
     while (i<size1 && j<size2)
     {
          if (a1[i]<a2[j])
          {
               marray[k]=a1[i];
               i++;
               k++;
          }
          else
          {
               marray[k]=a2[j];
               j++;
               k++;
          }
     }
     while (i<size1)
     {
          marray[k]=a1[i];
          k++;
          i++;
     }
     while (j<size2)
     {
          marray[k]=a2[j];
          k++;
          j++;
     }
     for (z = 0; z < tsize; z++)
     {
          printf("%d ",marray[z]);
     }
     return 0;
}