class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size() ;

        int index = 0 ;
        int count=0 ;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                swap(nums[i],nums[index++]) ;
                count++ ;
            }
        }
        return count ;
    }
};