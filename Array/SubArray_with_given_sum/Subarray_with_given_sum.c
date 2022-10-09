
// Brute froce method
// time complesxcity - (O)n^2

// #include <stdio.h>
// int main()
// {
//      int sum,s=15
//      ;
//      int arr[] = {1,2,3,4,5,6,7,8,9,10};
//      for (int i = 0; i < 10; i++)
//      {
//           sum=0;
//           for (int j = i; j < 10; j++)
//           {
//                sum+=arr[j];
//                if (sum==s)
//                {
//                     printf("(%d,%d)",i+1,j+1);
//                }
//           }
//      }

//      return 0;
// }



// #include <stdio.h>
// int main()
// {
//      int csum = 0, s = 15;
//      int arr[] = {1,2,3,4,5,6,7,8,9,10};
//      int left = 0;
//      int i=0;
//      for ( i = 0; i < 10; i++)
//      {
//           csum+=arr[i];
//           while (csum>s)
//           {
//                csum-=arr[left];
//                left++;
//           }
//           if (csum==s)
//           {
//                printf("%d,%d ",left+1,i+1);
//           }
//      }
//      return 0;
// }

// perfect method
// time complexcity - (O)n

#include <stdio.h>
int main()
{
     int csum = 0, s = 12;
     int arr[] = {1,2,3,7,5};
     int left = 0;
     int right=0;
     while (right<=5)
     {
          if (csum<s)
          {
               csum+=arr[right];
               right++;
          }
          else if (csum>s)
          {
               csum-=arr[left];
               left++;
          }
          else if (csum==s)
          {
               printf("%d,%d ",left+1,right);
               break;
          }  
     }
     return 0;
}