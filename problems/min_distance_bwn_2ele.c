#include <stdio.h>
int main()
{
     int x,y,count=0,a[10];
     for (int i = 0; i < 10; i++)
     {
          a[i]=10;
     }
     int arr[] = { 1, 3, 5, 4, 8, 2, 4, 3, 6, 5 };
     printf("Enter x: ");
     scanf("%d",&x);
     printf("Enter y: ");
     scanf("%d",&y);
     int size=10,j;
     for (int i = 0; i < size; i++)
     {
          if (arr[i]==x)
          {
               count=0;
               j=i;
               while (arr[j]!=y)
               {
                    count++;
                    j++;
               }
               // count++;
               a[i] = count;
          }
          else if (arr[i]==y)
          {
               count=0;
               j=i;
               while (arr[j]!=x)
               {
                    count++;
                    j++;
               }
               // count++;
               a[i] = count;
          }
     }
     int min=a[0];
     for (int i = 0; i < 10; i++)
     {
          if (a[i]<min)
          {
               min=a[i];
          }
     }
     printf("%d",min);
     // printf("%d",count);
     return 0;
}