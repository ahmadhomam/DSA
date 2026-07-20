class Solution {
public:
    typedef long long ll ;
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() ;
        int i=0 ;
        int j=0 ;
        int minsize = INT_MAX ;
        long long sum = 0 ;
        while(i<=j && j<n){
            sum += nums[j] ;
            while(sum >= target){
                minsize =  min(minsize,j-i+1 ) ;
                sum -= nums[i] ;
                i++  ; 
            }
            j++;
        }
        if(minsize != INT_MAX)
        return minsize ;
        else
        return 0 ;
    }
};