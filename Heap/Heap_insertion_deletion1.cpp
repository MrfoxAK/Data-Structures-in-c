#include <iostream>
using namespace std;

class heap
{
public:
     int arr[100];
     int n = 0;
     heap()
     {
          arr[0] = -1;
          n = 0;
     }
     void display()
     {
          for (int i = 1; i <= n; i++)
               cout << arr[i] << " ";
          cout << "\n";
     }
     void insert(int data)
     {
          n++;
          arr[n] = data;
          int i = n;
          while (i > 1)
          {
               int parent = i / 2;
               if (arr[i] > arr[parent])
               {
                    swap(arr[parent], arr[i]);
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
               cout << "Nothing to Delete\n";
               return;
          }
          else
          {
               arr[1] = arr[n];
               n--;
               int i = 1;
               while (i < n)
               {
                    int left = i * 2;
                    int right = i * 2 + 1;
                    if (left < n && arr[left] > arr[i])
                    {
                         swap(arr[i], arr[left]);
                         i = left;
                    }
                    if (right < n && arr[right] > arr[i])
                    {
                         swap(arr[i], arr[right]);
                         i = right;
                    }
                    else
                    {
                         return;
                    }
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
     h.deletion();
     h.display();
     return 0;
}
