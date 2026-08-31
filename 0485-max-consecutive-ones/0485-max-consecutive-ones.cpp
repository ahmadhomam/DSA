class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size() ;
        int maxsize = 0 ;

        int i=0 ;
        int j=0 ;
        while(j<n){
            if(nums[j] == 1){
                maxsize = max(maxsize,j-i+1) ;
                j++ ;
            }
            else{
                i = j+1 ;
                j++ ;
            }
        }
        return maxsize ;
    }
};