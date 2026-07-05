class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> ans ;

        //sort the array for dealing the duplicates and pointer shifting 
        sort(nums.begin(),nums.end()) ;

        for(int k=0;k<n;k++){
            int i= k+1 ;
            int j = n-1 ;

            if(k != 0 && nums[k] == nums[k-1])
            continue ;

            while( i<j){
                int total = nums[k] + nums[i] + nums[j] ;
                if(total == 0){
                    ans.push_back({nums[k],nums[i],nums[j]}) ;
                    i++ ,j-- ;

                    // Skip duplicates for i
                    while (i < j && nums[i] == nums[i - 1]) i++;
                    // Skip duplicates for j
                    while (i < j && nums[j] == nums[j + 1]) j--;
                }
                else if (total > 0){
                    j-- ;
                }
                else{
                    i++ ;
                }
            }
        }
        return ans ;
    }
};