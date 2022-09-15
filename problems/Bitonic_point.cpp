
class Solution {
    int findMaximum(int[] arr, int n) {
        // code here
        int max=arr[0];
        for(int i=0; i<n; i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
        return max;
    }
}