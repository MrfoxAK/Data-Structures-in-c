#include <stdio.h>

void printArray(int *A, int n)
{
     for (int i = 0; i < n; i++)
     {
          printf("%d ", A[i]);
     }
     printf("\n");
}

void bubbleSort(int *A, int n)
{
     int temp;
     int isSorted = 0;
     for (int i = 0; i < n - 1; i++) // For number of pass
     {
          printf("Working on pass number %d\n", i + 1);
          for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
          {
               if (A[j] > A[j + 1])
               {
                    temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
               }
          }
     }
}

void bubbleSortAdaptive(int *A, int n)
{
     int temp;
     int isSorted = 0;
     for (int i = 0; i < n - 1; i++) // For number of pass
     {
          printf("Working on pass number %d\n", i + 1);
          isSorted = 1;
          for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
          {
               if (A[j] > A[j + 1])
               {
                    temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                    isSorted = 0;
               }
          }
          if (isSorted)
          {
               return;
          }
     }
}

int main()
{
     // int A[] = {12, 54, 65, 7, 23, 9};
     int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
     // int A[] = {1, 2, 3, 4, 5, 6};
     int n = 11;
     printArray(A, n); // Printing the array before sorting
     bubbleSort(A, n); // Function to sort the array
     printArray(A, n); // Printing the array before sorting
     return 0;
}

// // Online C compiler to run C program online
// #include <stdio.h>

// int main()
// {
//      // Write C code here
//      int temp;
//      int arr[] = {1, 4, 2, 3, 6, 8};
//      for (int i = 0; i < 5; i++)
//      {
//           for (int j = 0; j < 5 - i; j++)
//           {
//                if (arr[j] > arr[j + 1])
//                {
//                     temp = arr[j];
//                     arr[j] = arr[j + 1];
//                     arr[j + 1] = temp;
//                }
//           }
//      }
//      for (int i = 0; i < 6; i++)
//      {
//           printf("[%d] ",arr[i]);
//      }
//      return 0;
// }