class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        // Your code here
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(arr[i]<arr[i+1]){
                    swap(arr[i],arr[i+1]);
                }
            }
            else{
                if(arr[i+1]<arr[i+2]){
                    swap(arr[i+1],arr[i+2]);
                }
            }
        }
        
    }
};
