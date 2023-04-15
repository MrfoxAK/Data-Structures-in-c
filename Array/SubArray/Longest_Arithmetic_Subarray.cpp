// Longest Arithmetic Subarray - Kickstart
#include <iostream>
using namespace std;

int main()
{
     int arr[5];
     int carray[5];
     int j = 0;
     int c = 0;
     int n = 7;
     int sum = 0;
     int mx = -1999999;
     for (int i = 0; i < n; i++)
     {
          cout << "Enter element at " << i << " ";
          cin >> arr[i];
     }
     int dif = arr[1] - arr[0];
     for (int i = 0; i < n;)
     {
          if (arr[i + 1] - arr[i] == dif)
          {
               c++;
               i++;
          }
          else
          {
               carray[j] = c;
               j++;
               c = 0;
               dif = arr[i + 1] - arr[i];
          }
     }
     int max = 0;
     for (int i = 0; i < j; i++)
     {
          if (carray[i] > max)
          {
               max = carray[i];
          }
     }
     cout << "The Longest Arithmetic Subarray is " << max + 1 << endl;
     return 0;
}