// #include <stdio.h>

// #define N 5

// // Function to calculate the determinant of a matrix
// int determinant(int matrix[N][N], int n) {
//     int det = 0;

//     // Base case: if the matrix is 1x1
//     if (n == 1) {
//         return matrix[0][0];
//     }

//     // Base case: if the matrix is 2x2
//     if (n == 2) {
//         return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
//     }

//     // Recursive case: for larger matrices
//     for (int i = 0; i < n; i++) {
//         // Calculate the cofactor
//         int cofactor[N - 1][N - 1];
//         for (int j = 1; j < n; j++) {
//             for (int k = 0, l = 0; k < n; k++) {
//                 if (k != i) {
//                     cofactor[j - 1][l++] = matrix[j][k];
//                 }
//             }
//         }

//         // Recursive call to calculate the determinant
//         det += matrix[0][i] * (i % 2 == 0 ? 1 : -1) * determinant(cofactor, n - 1);
//     }

//     return det;
// }

// int main() {
//     int matrix[N][N] = {
//         {2, 1, 0, 3, 4},
//         {-1, 0, 2, 1, 5},
//         {3, 2, -1, 4, 2},
//         {2, 3, 1, 0, -2},
//         {-1, 2, 3, -2, 1}
//     };

//     // Calculate and print the determinant
//     int det = determinant(matrix, N);
//     printf("Determinant: %d\n", det);

//     return 0;
// }




#define MAX 10000
    //here I was trying to make a "matrix" type to be able to return values in the function "subMatrix"
    struct Matrix
    {
        double a[MAX][MAX];
    };


    struct Matrix subMatrix(int n, double m[n][n], int I, int J);
    double determinant(int n, double M[n][n]);


    int main()
    {
        int n, k = 0;
        printf("how many rows does the matrix have"); 
        scanf("%d", &n);
        double Matrix[n][n];
        double temp[n * n];
        printf("enter the numbers in order with an enter after each one");
        //gathering all the data from the user
        for (int i = 0; i < n * n; i++)
        {
            scanf("%d", temp[i]);
        }
        //sorting the data into a matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Matrix[i][j] = temp[k];
                k++;
            }
        }
        //prints the determinant
        printf("%d",determinant(n,Matrix));

        return 0;
    }
    //this recursive function calculates the determinant 
    double determinant(int n, double M[n][n])
    {
        double det = 0;
        //the functions continues to call its self until n=2
        if (n == 2)
        {
            det = M[0][0] *M[1][1]-M[0][1]*M[1][0];
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                det += M[0][i] * determinant(n - 1, subMatrix(n, M, 0, i));
            }
        }



        return det;
    }
    //here I tried to make the subMatrix of a given matrix and one of its components
    //by sub matrix I mean the matrix that doesn't include the row and columns that are in line with one of the matrix componants
    struct Matrix subMatrix(int n, double m[n][n], int I, int J)
    {
        int i, a = 0, b = 0;
        int j;
        struct Matrix M[n - 1][n - 1];
        for (i = 0; i < n; i++)
        {
            if (i != I)
            {
                for (j = 0; j < n; j++)
                {
                    if (J != j)
                    {
                        M[a][b] = m[i][j];
                        b++;
                    }
                }
                a++;
            }
        }
        return M;
    }