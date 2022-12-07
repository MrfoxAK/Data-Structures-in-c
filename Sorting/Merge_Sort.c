#include <stdio.h>

void merge(int arr[],int low,int high,int mid){
     int i = low;
     int j = mid+1;
     int k = low;
     int marr[100];
     while (i<=mid && j<=high)
     {
          if (arr[i]<arr[j])
          {
               marr[k] = arr[i];
               k++;
               i++;
          }
          else
          {
               marr[k] = arr[j];
               k++;
               j++;    
          }
     }
     while (i<=mid)
     {
          marr[k] = arr[i];
          i++;
          k++;
     }
     while (j<=high)
     {
          marr[k] = arr[j];
          j++;
          k++;
     }
     for (int i = 0; i <= high; i++)
     {
          arr[i] = marr[i];
     }
     // for (int i = 0; i < high+1; i++)
     // {
     //      printf("%d ",marr[i]);
     // }
}

void MergeSort(int arr[],int low,int high){
     int mid;
     if (low<high)
     {
          mid = (low+high)/2;
          MergeSort(arr,low,mid);
          MergeSort(arr,mid+1,high);
          merge(arr,low,high,mid);
     }
}

int main()
{
     int arr[] = {7,15,2,8,10};
     // merge(arr,0,4,1);
     MergeSort(arr,0,4);
     for (int i = 0; i < 5; i++)
     {
          printf("%d ",arr[i]);
     }
     return 0;
}