// *******Important********

// The leaf node of a heap always lie btwn n/2+1 ---- n


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
          // This will take O(logn)
          void deletion(){
               if(size == 0){
                    cout<<"Nothing to Delete\n";
                    return;
               }
               else{
                    arr[1] = arr[size];
                    size--;
                    int i = 1;
                    while (i<size)
                    {
                         int leftIndex = 2*i;
                         int rightIndex = 2*i+1;
                         if(leftIndex < size && arr[i] < arr[leftIndex]){
                              swap(arr[i],arr[leftIndex]);
                              i = leftIndex;
                         }
                         else if(rightIndex < size && arr[i] < arr[rightIndex]){
                              swap(arr[i],arr[rightIndex]);
                              i = rightIndex;
                         }
                         else{
                              return;
                         }
                    }
               }
          }
};

// The time taken is O(logn)
void heapify(int arr[],int n, int i){
     int largest = i;
     int left = 2*i;
     int right = 2*i+1;
     if(left < n && arr[left]>arr[largest]){
          largest = left;
     }
     if(right < n && arr[right]>arr[largest]){
          largest = right;
     }
     if(largest != i){
          swap(arr[i],arr[largest]);
          heapify(arr,n,largest);
     }
}

int main()
{
     heap h;
     h.insert(50);
     h.insert(55);
     h.insert(53);
     h.insert(52);
     h.insert(54);
     h.display();
     h.deletion();
     h.display();
     int arr[] = {-1,54,53,55,52,50};
     int n = 5;
     for (int i = n/2; i > 0; i--)
     {
          heapify(arr,n,i);
     }
     for (int i = 1; i <= n; i++)
     {
          cout<<arr[i]<<" ";
     }
     return 0;
}
