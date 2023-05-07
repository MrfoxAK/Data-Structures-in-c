#include <iostream>
#include <vector>
using namespace std;

int first_occ(int arr[],int size,int key,int index){
     if(index==size){
          return -1;
     }
     if(arr[index] == key){
          return index;
     }
     return first_occ(arr,size,key,index+1);
}

int last_occ(int arr[],int size,int key,int index){
     static int temp = 0;
     if(index==size){
          if(temp==0){
               return -1;
          }
          else{
               return temp;
          }
     }
     if(arr[index] == key){
          temp = index;
     }
     last_occ(arr,size,key,index+1);
}

int main()
{
     int arr[] = {4,2,1,2,5,2,7};
     cout<<"The first occurence of 2 is "<<first_occ(arr,7,2,0)<<endl;
     cout<<"The last occurence of 2 is "<<last_occ(arr,7,2,0)<<endl;
     return 0;
}