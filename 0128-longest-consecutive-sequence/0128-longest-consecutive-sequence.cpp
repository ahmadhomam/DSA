class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size() ;
        unordered_set<int> set ;
        for(int num: nums)
        set.insert(num) ;


        int maxlen = 1 ;
        int len = 1 ;
        if(n == 0 || n== 1)
        return n ;

        for(int st:set){
            if(set.count(st-1) == 0){
                len = 1 ;
                int x = st+1 ;
                while(set.count(x) != 0){
                    len++ ;
                    x = x+1 ;
                }
                maxlen = max(maxlen,len) ;
            }
        }
        return maxlen ;
    }
};