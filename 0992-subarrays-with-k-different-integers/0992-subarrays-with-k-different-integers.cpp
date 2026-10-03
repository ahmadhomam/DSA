class Solution {
public:
    int Atmost(vector<int> &nums, int k){
        int n = nums.size() ;
        int i =0 ;
        int j =0  ;
        int count = 0 ;
        unordered_map<int,int> map;
        while(j<n){
            //calculations
            map[nums[j]]++  ;

            //the window become invalid 
            while(map.size() > k){
                map[nums[i]]-- ;
                if(map[nums[i]] == 0)
                map.erase(nums[i]) ;

                i++ ;
            }
            // here this count adding 
            count += j-i+1 ;
            j++ ;
        }
        return count ;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if(k == 1)
        return Atmost(nums,k) ;

        return Atmost(nums,k)-Atmost(nums,k-1) ;
    }
};