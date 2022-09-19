// This programm is for array right rotate

#include<stdio.h>

int main(){
     int size,rotation;
     printf("Enter the size of the array: ");
     scanf("%d",&size);
     int arr[size];
     printf("Enter array element: ");
     for (int i = 0; i < size; i++)
     {
          scanf("%d",&arr[i]);
     }
     printf("The array is : ");
     for (int i = 0; i < size; i++)
     {
          printf("[%d] ",arr[i]);
     }
     printf("\n");
     printf("Enter how many time u want to rotate: ");
     scanf("%d",&rotation);
     for (int i = 0; i < rotation; i++)
     {
          int lastelmnt = arr[size-1];
          for (int j = size-1; j >= 0; j--)
          {
               arr[j+1] = arr[j];
          }
          arr[0] = lastelmnt;
     }
     printf("Now The array is : ");
     for (int i = 0; i < size; i++)
     {
          printf("[%d] ",arr[i]);
     }
     return 0;
}