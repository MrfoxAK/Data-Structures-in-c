#include <stdio.h>

int size = 9;

void swap(int *a, int *b)
{
     int temp = *b;
     *b = *a;
     *a = temp;
}

void printArray(int array[], int size)
{
     for (int i = 0; i < size; ++i)
          printf("%d ", array[i]);
     printf("\n");
}

void insertHeap(int arr[], int value)
{
     size = size+1;
     arr[size] = value;
     int i = size;
     int parent = i/2-1;
     printf("\nThe parent of %d is %d\n",value,arr[parent]);
     while (i>1)
     {
          int parent = i/2-1;
          if(arr[parent] < arr[i]){
               swap(&arr[parent],&arr[i]);
               i = parent;
          }
          else{
               return;
          }
     }
}

int main()
{
     int arr[50] = {70,50,40,45,35,39,16,10,9};
     // there is a problem for static array
     // it will not change array size as it's a static type
     printArray(arr,size);
     int value = 60;
     insertHeap(arr,value);
     printArray(arr,size);
     return 0;
}