#include <stdio.h>
int main()
{
    int temp,flag = 0;
    int arr[] = {7, 11, 9, 2, 17, 4};
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 5 - i; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
                flag = 1;
            }
        }
        // IF no two elements were swapped by inner loop, then break
        if (flag==0)
        {
            break;
        }
    }
    for (int j = 0; j < 6; j++)
    {
        printf("%d ", arr[j]);
    }
    return 0;
}