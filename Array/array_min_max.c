#include<stdio.h>
int main()
{
    int arr[] = {10,3,4,66,8,9};
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < 6; i++)
    {
        if (min>arr[i])
        {
            min=arr[i];
        }
        if (max<arr[i])
        {
            max=arr[i];
        }
    }
    printf("The min value is: %d\n",min);
    printf("The max value is: %d\n",max);
    return 0;
}