class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() ;
        int minsize = INT_MAX;

        int i=0 ;
        int j =0 ;
        int sum = 0 ;
        while(j<n) {
            //calculations
            sum += nums[j] ;

            //shrink till valid 
            while(sum >= target){
                minsize = min(minsize,j-i+1) ;

                sum -= nums[i] ;
                i++ ;

            }
            j++ ;

        }

        return minsize == INT_MAX ? 0 : minsize ;
    }
};