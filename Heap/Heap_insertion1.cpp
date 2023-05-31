#include<iostream>
using namespace std;

class heap{
     public:
          int arr[100];
          int n=0;
          heap(){
               arr[0] = -1;
               n = 0;
          }
          void display(){
               for (int i = 1; i <= n; i++)
                    cout<<arr[i]<<" ";
          }
          void insert(int data){
               n++;
               arr[n] = data;
               int i = n;
               while (i>1)
               {
                    int parent = i/2;
                    if(arr[i]>arr[parent]){
                         swap(arr[parent], arr[i]);
                         i = parent;
                    }
                    else{
                         return;
                    }
               }
               
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
