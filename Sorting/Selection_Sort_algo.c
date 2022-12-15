#include <stdio.h>

void selection_sort(int arr[], int size)
{
     int min_index,temp;
     for (int i = 0; i < size; i++)
     {
          min_index = i;
          for (int j = i+1; j < size; j++)
          {
               if (arr[j]<arr[min_index])
               {
                    min_index = j;
               }
          }
          temp = arr[i];
          arr[i] = arr[min_index];
          arr[min_index] = temp;
     }
}

void printArray(int *A, int n)
{
     for (int i = 0; i < n; i++)
     {
          printf("%d ", A[i]);
     }
     printf("\n");
}

int main()
{
     int arr[] = {12, 0, 21, 4, 16, 7};
     printArray(arr, 6);
     // Sort(arr,6);
     selection_sort(arr, 6);
     printArray(arr, 6);
     return 0;
}