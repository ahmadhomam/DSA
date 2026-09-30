class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n  = nums.size()  ;
        int i =0 ;
        int j =0 ;
        int maxcount  = -1 ;
        int zerocount = 0 ;
        while( j< n){
                if(nums[j] == 0)
                zerocount++ ;
                

            //the condition overflow 
            while(zerocount > k){
                if(nums[i] == 0)
                zerocount-- ;

                i++ ;
            }

            //found valid  
            maxcount = max(maxcount, j-i+1) ;

            j++ ;
        }
        return maxcount ;
    }
};