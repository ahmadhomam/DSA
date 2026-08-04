class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ;
        vector<int> ans ;

        int prev = nums[0] ;

        for(int i=1;i<nums.size();i++){
            if(nums[i] != prev+1){
                prev++ ;
                while(prev != nums[i]){
                    ans.push_back(prev) ;
                    prev++ ;
                }
            }
            prev = nums[i] ;
        }

        return ans ;
    }
};