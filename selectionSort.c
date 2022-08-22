#include <stdio.h>

void SelectionSort(int arr[],int n){
     int minIndex,temp;
     for (int i = 0; i < n; i++)
     {
          minIndex=i;
          for (int j = i+1; j < n; j++)
          {
               if (arr[minIndex]>arr[j])
               {
                    minIndex=j;
               }
          }
          temp = arr[i];
          arr[i] = arr[minIndex];
          arr[minIndex] = temp;
     }
}

void display(int arr[],int size){
     for (int i = 0; i < size; i++)
     {
          printf("%d ",arr[i]);
     }
}

int main()
{
     int arr[] = {4,6,2,3,78,1,34};
     SelectionSort(arr,7);
     display(arr,7);
     return 0;
}