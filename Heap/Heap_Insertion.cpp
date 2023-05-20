#include<iostream>
using namespace std;

class heap{
     public:
          int arr[100];
          int size = 0;
          heap(){
               arr[0] = -1;
               size = 0;
          }
          // This will take O(logn)
          void insert(int val){
               size = size+1;
               int i = size;
               arr[i] = val;
               while (i>1)
               {
                    int parent = i/2;
                    if(arr[parent]<arr[i]){
                         swap(arr[parent],arr[i]);
                         i = parent;
                    }
                    else{
                         return;
                    }
               }
          }
          void display(){
               for (int i = 1; i <= size; i++)
               {
                    cout<<arr[i]<<" ";
               }
               cout<<endl;
          }
};


int main()
{
     heap h;
     h.insert(50);
     h.insert(55);
     h.insert(53);
     h.insert(52);
     h.insert(54);
     h.display();
     return 0;
}
