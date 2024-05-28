#include <stdio.h>

// Traversal
void display(int arr[], int n)
{
     for (int i = 0; i < n; i++)
     {
          printf("%d ", arr[i]);
     }
}

int partition(int arr[], int low, int high){
     int pivet = arr[low];
     int temp;
     int i = low;
     int j = high;
     while (i < j)
     {
          while (arr[i]<=pivet)
          {
               i++;
          }
          while (arr[j]>pivet)
          {
               j--;
          }
          if (i < j)
          {
               temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
          }
     }
     temp = arr[low];
     arr[low] = arr[j];
     arr[j] = temp;
     return j;
}

void Quick_Sort(int arr[], int low, int high){
     int partition_index;
     if (low<high)
     {
          partition_index = partition(arr, low, high);
          Quick_Sort(arr, low, partition_index-1);
          Quick_Sort(arr, partition_index+1, high);
     }
}

int main()
{
     int arr[] ={5, 7, 2, 68, 10, 43, 2};
     int size = 7;
     display(arr, size);
     Quick_Sort(arr, 0, size - 1);
     printf("\n");
     display(arr, size);
     return 0;
     return 0;
}