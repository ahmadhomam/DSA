class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m ; //map that store frequency of certain prefix sum ;
        //m[0] = 1 ; // important for question perpose ;

        int count =0 ;
        int prefix = 0 ;
        for(int i=0;i<nums.size();i++){
            prefix += nums[i] ;
            //for the subarray with sum k exists , a subarray with sum (prefix-k) exist ;
            if(prefix == k)
            count++ ;

            count += m[prefix-k] ;
            m[prefix]++ ;
        }
        return count ;
    }
};