#include <stdio.h>

#define SIZE 3 // Size of the matrix

int main()
{
     int A[SIZE][SIZE]; // Matrix 1
     int B[SIZE][SIZE]; // Matrix 2
     int C[SIZE][SIZE]; // Resultant matrix

     int row, col, i, sum;

     /* Input elements in first matrix from user */
     printf("Enter elements in matrix A of size %dx%d: \n", SIZE, SIZE);
     for (row = 0; row < SIZE; row++)
     {
          for (col = 0; col < SIZE; col++)
          {
               scanf("%d", &A[row][col]);
          }
     }

     /* Input elements in second matrix from user */
     printf("\nEnter elements in matrix B of size %dx%d: \n", SIZE, SIZE);
     for (row = 0; row < SIZE; row++)
     {
          for (col = 0; col < SIZE; col++)
          {
               scanf("%d", &B[row][col]);
          }
     }

     /*
      * Multiply both matrices A*B
      */
     // i = 0;
     for (row = 0; row < SIZE; row++)
     {
          for (col = 0; col < SIZE; col++)
          {
               sum = 0;
               for (i = 0; i < SIZE; i++)
               {
                    sum += A[row][i] * B[i][col];
               }
               C[row][col] = sum;
          }
     }

     /* Print product of the matrices */
     printf("\nProduct of matrix A * B = \n");
     for (row = 0; row < SIZE; row++)
     {
          for (col = 0; col < SIZE; col++)
          {
               printf("%d ", C[row][col]);
          }
          printf("\n");
     }

     return 0;
}