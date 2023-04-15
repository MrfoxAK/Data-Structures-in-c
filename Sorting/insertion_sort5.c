#include <stdio.h>

void insertionSort(int * a,int n){
     int key,j=0;
     for (int i = 0; i < n; i++)
     {
          key = a[i];
          j=i-1;
          while (key<a[j] && j>-1)
          {
               a[j+1] = a[j];
               j--;
          }
          a[j+1] = key;
     }
}

void printarray(int* a,int n){
     for (int i = 0; i < n; i++)
     {
          printf("%d ",a[i]);
     }
}

int main()
{
     int arr[] = {12,54,45,5,23,9};
     int n=6;
     printarray(arr,n);
     insertionSort(arr,n);
     printf("\n");
     printarray(arr,n);
     return 0;
}