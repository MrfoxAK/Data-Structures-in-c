#include <stdio.h>
int main()
{
     int arr[3][3] = {
                    {1,12,33},
                    {41,53,26},
                    {17,82,92}
                    };
     int * p = &arr[0][0];
     printf("%d\n",*(arr+1));
     printf("%d\n",*(*(arr+1)+1));
     return 0;
}