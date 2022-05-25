// Binary search & bubble sort without using function
#include <stdio.h>
int main()
{
    int n, temp;
    printf("Enter the no of element in array: ");
    scanf("%d", &n);
    int arr[n];
    // taking user input array
    for (int i = 0; i < n; i++)
    {
        printf("Enter element at %d: ", i);
        scanf("%d", &arr[i]);
    }
    // bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // element to be search
    int element;
    printf("Enter the element: ");
    scanf("%d", &element);
    // binary search
    int low = 0, high = n, flag = 0;
    int mid;
    mid = (low + high) / 2;
    while (low <= high)
    {
        if (arr[mid] == element)
        {
            flag = 1;
            break;
        }
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
    }
    if (flag == 1)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }
    return 0;
}