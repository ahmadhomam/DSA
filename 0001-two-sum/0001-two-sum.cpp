class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map ;
        for(int i=0;i<nums.size();i++){
            int left= target-nums[i] ;
            if(map.find(left) != map.end()){
                return {i,map[left]} ;
            }
            map[nums[i]] = i ;
        }
        return {-1,-1} ;
    }
};