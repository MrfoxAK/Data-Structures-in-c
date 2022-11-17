class Solution{
public:
	// #define ll long long

    int max(int arr[],int start, int size){
     int max=0;
     for (int i = start; i <= size; i++)
     {
          if (max<arr[i])
          {
               max = arr[i];
          }
     }
     return max;
}

	ll countSubarray(int arr[], int n, int k) {
	    // code here
	    ll count=0,j=0;
     for (int i = 0; i < n; i++)
     {
          if (arr[i]>k)
          {
               count++;
          }
          j=i+1;
          while (j<n)
          {
               int maxi = max(arr,i,j);
               if (maxi>k)
               {
                    count++;
                    j++;
               }
               else
               {
                    break;
               }
          }
     }
     return count;
	}
};