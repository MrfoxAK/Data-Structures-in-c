#include <iostream>
using namespace std;

class heap
{
public:
     int arr[100];
     int size = 0;
     heap()
     {
          arr[0] = -1;
          size = 0;
     }
     int data;
     void insert(int val)
     {
          size += 1;
          arr[size] = val;
          int i = size;
          while (i > 1)
          {
               int parent = i / 2;
               if (arr[parent] < arr[i])
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
     void display()
     {
          for (int i = 1; i <= size; i++)
          {
               cout << arr[i] << " ";
          }
          cout << endl;
     }
     void deletion()
     {
          if (size == 0)
          {
               cout << "Nothing to Delete\n";
               return;
          }
          else
          {
               arr[1] = arr[size];
               size--;
               int i = 1;
               while (i < size)
               {
                    int left = i * 2;
                    int right = i * 2 + 1;
                    if (left < size && arr[left] > arr[i])
                    {
                         swap(arr[i], arr[left]);
                         i = left;
                    }
                    if (right < size && arr[right] > arr[i])
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
