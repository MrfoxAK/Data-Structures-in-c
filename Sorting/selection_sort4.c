#include <stdio.h>

void selection_sort(int arr[],int size){
     int min_index,temp;
     for (int i = 0; i < size; i++)
     {
          min_index=i;
          for (int j = i+1; j < size; j++)
          {
               if (arr[j]<arr[min_index])
               {
                    min_index = j;
               }
          }
          temp = arr[i];
          arr[i] = arr[min_index];
          arr[min_index] = temp;
     }
}

void traversal(int arr[],int size){
     for (int i = 0; i < size; i++)
     {
          printf("%d ",arr[i]);
     }
}

int main()
{
     int arr[] = {4,2,5,45,6,9,65,43};
     int size=8;
     traversal(arr,size);
     selection_sort(arr,size);
     printf("\n");
     traversal(arr,size);
     return 0;
}