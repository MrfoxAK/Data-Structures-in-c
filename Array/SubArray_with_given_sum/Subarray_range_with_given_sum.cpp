class Solution
{
public:
     // Function to count the number of subarrays which adds to the given sum.
     int subArraySum(vector<int> &arr, int tar)
     {
          // Your code here
          unordered_map<int, int> mp;
          int res = 0;
          int ans = 0;
          for (int i = 0; i < arr.size(); i++)
          {
               res += arr[i];
               if (res == tar)
                    ans++;
               else if (mp.find(res - tar) != mp.end())
                    ans += mp[res - tar];
               mp[res]++;
          }
          return ans;
     }
};