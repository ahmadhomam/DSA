class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size() ;
        sort(nums.begin(),nums.end()) ;

        int maxlen = 1 ;
        int cnt =1 ;
        int lastmin = INT_MIN ;

        if(n == 0)
        return n ;

        for(int i=0;i<n;i++){
            if(nums[i] -1 == lastmin){
                cnt++  ;
                lastmin = nums[i] ;
            }
            else if(nums[i] != lastmin ){
                cnt = 1 ;
                lastmin = nums[i] ;
            }
            maxlen = max(maxlen,cnt) ;
        }

        return maxlen ;
    }
};