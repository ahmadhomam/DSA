class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size() ;
        int maxsum = INT_MIN ;
        int i =0 ;
        int j =0 ;
        int sum = 0 ;
        
        while(j<n){
            sum += arr[j] ;
            
            if(j-i+1 < k)
            j++ ;
            
            else if(j-i+1 == k){
                maxsum = max(maxsum,sum) ;
                sum -= arr[i++] ;
                j++ ;
            }
        }
        return maxsum ;
    }
};