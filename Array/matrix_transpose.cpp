#include <iostream>
using namespace std;

int main()
{
     int n, m;
     cout << "Enter the size NxM: \n";
     cin >> n >> m;
     int arr[n][m];
     int trans[n][m];
     int row_start = 0, row_end = n - 1, col_start = 0, col_end = m - 1;
     cout << "Enter the array elements: \n";
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cin >> arr[i][j];
          }
     }
     cout<<"Before Transpose the array is "<<endl;
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cout<< arr[i][j] << " ";
          }
          cout<<"\n";
     }
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               trans[i][j] = arr[j][i];
          }
     }
     cout<<"After Transpose the array is "<<endl;
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cout<< trans[i][j] << " ";
          }
          cout<<"\n";
     }
     return 0;
}