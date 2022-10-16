class Solution
{
public:
     vector<int> findLeastGreater(vector<int> &arr, int n)
     {
          for (int i = 0; i < n; i++)
          {
               for (int j = i + 1; j < n; j++)
               {
                    if (arr[j] > arr[i] && arr[j] < arr[j + 1])
                    {
                         arr[i] = arr[j];
                    }
                    else
                    {
                         arr[i] = -1;
                    }
               }
          }
     }
};