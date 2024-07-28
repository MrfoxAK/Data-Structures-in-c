#include <stdio.h>

void display(int arr[], int size){
     for (int i = 0; i < size; i++)
     {
          printf("%d ",arr[i]);
     }
}

void pos_insert(int arr[],int size, int pos, int ele){
     int index = pos-1;
     for (int i = size-1; i >= index; i--)
     {
          arr[i + 1] = arr[i];
     }
     arr[index] = ele;
}

int main()
{
     int arr[10] = {1,2,4,6,70};
     int size = 5, ele = 45, pos = 3;
     display(arr,size);
     pos_insert(arr,size,pos,ele);
     size++;
     printf("\nNow the array is :- \n");
     display(arr,size);
     return 0;
}