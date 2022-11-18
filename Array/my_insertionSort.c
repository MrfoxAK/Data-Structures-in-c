#include <stdio.h>

void my_nub_insertionSort(int * a,int n){
     int key,j;
     for (int i = 0; i < n; i++)
     {
        //   key = a[i];
          j=i+1;
          while (j>=0)
          {
               if(a[j] > a[j-1] && (j-1)>=0){
                   key = a[j];
                   a[j] = a[j-1];
                   a[j-1] = key;
               }
               j--;
          }
        //   a[j+1] = key;
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
     my_nub_insertionSort(arr,n);
     printf("\n");
     printarray(arr,n);
     return 0;
}