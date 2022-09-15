#include <stdio.h>

void insertion_sort(int *arr,int size){
     // loop for pass
     int key,j;
     for (int i = 0; i < size; i++)
     {
          int key = arr[i];
          j=i-1;
          while (j>=0 && arr[j]>key)
          {
               arr[j+1] = arr[j];
               j--;
          }
          arr[j+1]=key;
     }
}

void display(int *arr,int size){
     for (int i = 0; i < size; i++)
     {
          printf("%d ",arr[i]);
     }
}

int main()
{
     int arr[] = {12,54,65,7,23,9};
     display(arr,6);
     insertion_sort(arr,6);
     printf("\n");
     display(arr,6);
     return 0;
}