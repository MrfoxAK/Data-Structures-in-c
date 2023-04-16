// record breaking day - Kickstart
#include <iostream>
using namespace std;

int main()
{
     int n=8;
     int arr[8];
     int carray[5];
     int j=0;
     int c=0;
     int sum=0;
     int mx=-1999999;
     for (int i = 0; i < n; i++)
     {
          cout<<"Enter element at "<<i<<" ";
          cin>>arr[i];
     }
     for (int i = 0; i < n; i++)
     {
          if(arr[i]>arr[i+1] && arr[i]>mx){
               c++;
          }
          mx = max(mx,arr[i]);
     }
     cout<<"The Total Record Breaking Day is "<<c<<endl;    
     return 0;
}