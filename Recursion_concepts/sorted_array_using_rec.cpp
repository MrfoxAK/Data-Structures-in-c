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
     if(curr < curr_1){
          i = 1;
     }
     if(i==1){
          return 0;
     }
     sorted(arr,n-1);
}

bool Sorted_or_not(int arr[],int n){
     if(n==1){
          return true;
     }
     bool restarray = sorted(arr+1,n-1);
     return (arr[0]<arr[1] && restarray);
}

int main()
{
     int arr[] = {1,2,3,4,5,6,7};
     // Own Logic
     if(sorted(arr,6))
          cout<<"The Array is Sorted"<<endl;
     else
          cout<<"The Array is Not Sorted"<<endl;
     // Apna College-YT Logic
     if(Sorted_or_not(arr,6))
          cout<<"The Array is Sorted"<<endl;
     else
          cout<<"The Array is Not Sorted"<<endl;
     return 0;
}