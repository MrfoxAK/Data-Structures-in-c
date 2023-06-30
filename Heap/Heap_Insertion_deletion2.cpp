#include <iostream>
using namespace std;

class Heap
{
public:
     int arr[100];
     int n = 0;
     Heap()
     {
          arr[0] = -1;
          n = 0;
     }
     void display()
     {
          for (int i = 1; i <= n; i++)
               cout << arr[i] << " ";
          cout<<endl;
     }
     void insert(int data)
     {
          n++;
          arr[n] = data;
          int i = n;
          while (i > 1)
          {
               int parent = i / 2;
               if (arr[parent] < arr[i])
               {
                    swap(arr[i], arr[parent]);
                    i = parent;
               }
               else
               {
                    return;
               }
          }
     }
     void deletion()
     {
          if (n == 0)
          {
               cout << "The Heap is Empty" << endl;
          }
          arr[1] = arr[n];
          n--;
          int i = 1;
          while (i < n)
          {
               int leftchild = i * 2;
               int rightchild = i * 2 + 1;
               if (arr[i] < arr[leftchild] && leftchild < n)
               {
                    swap(arr[i], arr[leftchild]);
                    i = leftchild;
               }
               else if (arr[i] < arr[rightchild] && rightchild < n)
               {
                    swap(arr[i], arr[rightchild]);
                    i = rightchild;
               }
               else
               {
                    return;
               }
          }
     }
};

int main()
{
     Heap h;
     h.insert(50);
     h.insert(55);
     h.insert(53);
     h.insert(52);
     h.insert(54);
     h.display();
     h.deletion();
     h.display();
     return 0;
}
