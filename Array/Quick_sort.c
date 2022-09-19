#include <stdio.h>

// Traversal
void display(int arr[], int n)
{
     for (int i = 0; i < n; i++)
     {
          printf("%d ", arr[i]);
     }
}

int partition(int arr[],int low,int high){
     int pivet = arr[low];
     int i=low;
     int j=high;
     int temp;

     while (i<j)
     {
          while (arr[i]<=pivet)
          {
               i++;
          }
          while (arr[j]>pivet)
          {
               j--;
          }
          if (i<j)
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

void QuickSort(int arr[],int low,int high){
     int partitionindex;
     if (low<high)
     {
          partitionindex= partition(arr,low,high);
          QuickSort(arr,low,partitionindex-1);
          QuickSort(arr,partitionindex+1,high);
     }
}

int main()
{
     int arr[] = {3,5,2,1,4,78,9};
     display(arr,7);
     printf("\n");
     QuickSort(arr,0,7);
     display(arr,7);
     return 0;
}