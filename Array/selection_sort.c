#include <stdio.h>

void printArray(int *A, int n)
{
     for (int i = 0; i < n; i++)
     {
          printf("%d ", A[i]);
     }
     printf("\n");
}

// void Sort(int * arr,int n){
//      int temp;
//      for (int i = 0; i < n; i++)
//      {
//           for (int j = i+1; j < n; j++)
//           {
//                if (arr[i]>arr[j])
//                {
//                     temp = arr[i];
//                     arr[i] = arr[j];
//                     arr[j] = temp;
//                }
//           }
//      }
// }

void selectionSort(int * arr,int n){
     int indexOfMin,temp;
     for (int i = 0; i < 5; i++)
     {
          indexOfMin=i;
          for (int j = i+1; j < 6; j++)
          {
               if(arr[indexOfMin]>arr[j]){
                    indexOfMin=j;
               }
          }
          temp = arr[i];
          arr[i] = arr[indexOfMin];
          arr[indexOfMin]=temp;
     }
}

int main()
{
     int arr[]={1,0,2,4,6,7};
     printArray(arr,6);
     // Sort(arr,6);
     selectionSort(arr,6);
     printArray(arr,6);
     return 0;
}

// void selectionSort(int* arr,int n){
//      int minindex,temp;
//      for (int i = 0; i < n; i++)
//      {
//           minindex=i;
//           for (int j = i+1; j < n; j++)
//           {
//                if (arr[minindex]>arr[j])
//                {
//                     minindex = j;                  
//                }
//           }
//           temp = arr[i];
//           arr[i] = arr[minindex];
//           arr[minindex] = temp;
//      }
// }
