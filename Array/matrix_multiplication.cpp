#include <iostream>
using namespace std;

int main()
{
     int n, m;
     cout << "Enter the size NxM: \n";
     cin >> n >> m;
     int m1[n][m];
     int m2[n][m];
     int multiply[n][m];
     int sum=0;
     int row_start = 0, row_end = n - 1, col_start = 0, col_end = m - 1;
     cout << "Enter the array elements: \n";
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cin >> m1[i][j];
          }
     }
     cout<<"Enter the 2nd matrix: "<<endl;
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cin >> m2[i][j];
          }
     }
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               sum=0;
               for (int k = 0; k < m; k++)
               {
                    sum+=m1[i][k]*m2[k][j];
               }
               multiply[i][j] = sum;
          }
     }
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cout<<multiply[i][j]<< " ";
          }
          cout<<"\n";
     }
     return 0;
}