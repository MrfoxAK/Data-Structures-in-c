#include <stdio.h>
int main()
{
     int arr[] = {1,6,2};
     
     
     int min;
     
     int j=0;

     for (int i = 0; i < 3; i++)
     {
          int currElement=arr[i];
          j=i-1;

          while (j>=0)
          {
               if (arr[j]<currElement)
               {
                    break;
               }
               j--;
          }
          if (j<0)
          {
               printf("%d ",-1);
          }
          else{
          printf("%d ",arr[j]);
          }
     }
     
     
     
     return 0;
}