class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size() ;

        sort(nums.begin(),nums.end()) ;
        int closest = INT_MAX ;
        int ans ;

        for(int i=0;i<n;i++){
            int j = i+1 ;
            int k =n-1 ;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k] ;

                if(sum == target)
                return sum ;

                if(abs(target-sum) < closest){
                    closest = abs(target-sum) ;
                    ans = sum ;
                }

                if(sum > target)
                k-- ;
                else
                j++ ;
                    
            }
        }
        return ans ;

    }
};