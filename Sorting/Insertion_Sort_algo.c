#include <stdio.h>

void insertionSort(int * a,int n){
     int curr_element,j;
     for (int i = 0; i < n; i++)
     {
          curr_element = a[i];
          j=i-1;
          while (j>=0 && a[j]>curr_element)
          {
               a[j+1]=a[j];
               j--;
          }
          a[j+1] = curr_element;
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
     // 7 8 9 3 10
     int arr[] = {12,54,45,5,23,9};
     int n=6;
     printarray(arr,n);
     insertionSort(arr,n);
     printf("\n");
     printarray(arr,n);
     return 0;
}