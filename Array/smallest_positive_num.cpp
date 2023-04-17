#include <iostream>
using namespace std;

int main()
{
     int arr[] = {0, -9, 1, 2, 3, -4, 5};
     int n = 6;
     int prev = arr[0];
     for (int i = 0; i < n; i++)
     {
          if ((prev + 1 != arr[i + 1]) && (arr[i + 1] > 0) && (i > 0))
          {
               cout << prev + 1 << endl;
               break;
          }
          if (arr[i + 1] > 0)
          {
               prev = arr[i + 1];
          }
          else
          {
               continue;
          }
     }
     return 0;
}