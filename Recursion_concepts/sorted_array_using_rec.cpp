#include <iostream>
#include <vector>
using namespace std;

int sorted(int arr[],int n){
     if(n==0){
          return 1;
     }
     static int i = 0;
     int curr = arr[n];
     int curr_1 = arr[n-1];
     cout<<"prev is "<<curr<<" curr is "<<curr_1<<" i is "<<i<<endl;
     if(curr < curr_1){
          i = 1;
     }
     if(i==1){
          return 0;
     }
     sorted(arr,n-1);
}

int main()
{
     int arr[] = {1,2,3,4,5,6,7};
     if(sorted(arr,6))
          cout<<"The Array is Sorted"<<endl;
     else
          cout<<"The Array is Not Sorted"<<endl;
     return 0;
}