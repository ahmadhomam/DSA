class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size() ;
        int i =0 ;
        int j =0 ;

        int count = 0 ;
        int product = 1;
        if(k<= 1)
            return 0  ;
        while(j<n){
            //calculations
            product *= nums[j] ;

            // shrinking the window if found invalid 
            while(product >= k){
                product = (product/ nums[i]) ;
                i++ ;
            }

            //valid window
            count += j-i+1 ;

            j++ ;
        }
        return count ;
    }
};