class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size() ;
        int maxsize = 0 ;

        int i=0 ;
        int j=0 ;
        int size =0 ;
        while(j<n){
            //calculations.
            size++ ;
            //invalid shrinking
            if(nums[j] == 0){
                size = 0 ;
                i = j ;
            }
            //found valid update the answer
            maxsize = max(maxsize,size) ;
            j++ ;

        }
        return maxsize ;
    }
};