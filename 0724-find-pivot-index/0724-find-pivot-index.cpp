class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size()  ;
        int lefttotal = 0 ;
        int total =0 ;

        for(auto num : nums){
            total += num ;
        }

        for (int i=0;i<n;i++){
            int righttotal = total-lefttotal-nums[i] ;
            if(righttotal == lefttotal)
            return i ;

            lefttotal += nums[i] ;
        }
        return -1 ;
    }
};