
/* _push function to insert elements of array to
   stack
*/
stack<int> _push(int arr[], int n)
{
     stack<int> s;
     for (int i = 0; i < n; i++)
     {
          s.push(arr[i]);
     }
     return s;
}

void _pop(stack<int> s)
{
     while (!s.empty())
     {
          cout << s.top() << " ";
          s.pop();
     }
}