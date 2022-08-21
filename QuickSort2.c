#include <stdio.h>

// Traversal
void display(int arr[], int n)
{
     for (int i = 0; i < n; i++)
     {
          printf("%d ", arr[i]);
     }
}

int partion(int arr[],int low,int high){
     int pivet = arr[low];
     int start=low,end=high,temp;
     while (start<end)
     {
          while (arr[start]<=pivet)
          {
               start++;
          }
          while (arr[end]>pivet)
          {
               end--;
          }
          if (start<end)
          {
               temp=arr[start];
               arr[start] = arr[end];
               arr[end] = temp;
          }
     }
     temp = arr[low];
     arr[low] = arr[end];
     arr[end] = temp;
     return end;
}

void QuickSort(int arr[],int low,int high){
     int partitionIndex;
     if (low<high)
     {
          partitionIndex=partion(arr,low,high);
          QuickSort(arr,low,partitionIndex-1);
          QuickSort(arr,partitionIndex+1,high);
     }
}

int main()
{
     int arr[] = {2,5,23,4,1,45,79,6};
     QuickSort(arr,0,7);
     display(arr,8);
     return 0;
}