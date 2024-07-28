#include <stdio.h>

void display(int arr[], int size){
     for (int i = 0; i < size; i++)
     {
          printf("%d ",arr[i]);
     }
}

void pos_deletion(int arr[],int size, int pos){
     int index = pos-1;
     for (int i = index; i < size; i++)
     {
          arr[i] = arr[i+1];
     }
}

int main()
{
     int arr[10] = {1,2,4,6,70};
     int size = 5, pos = 4;
     display(arr,size);
     pos_deletion(arr,size,pos);
     size--;
     printf("\nNow the array is :- \n");
     display(arr,size);
     return 0;
}