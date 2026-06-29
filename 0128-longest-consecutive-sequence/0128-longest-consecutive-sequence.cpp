class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set ;
        for(int x : nums)
        set.insert(x) ;

        int maxlen = 0 ;
        int len = 1 ;
        if(set.size() == 0)
        return 0 ;

        for(int st : set){
            if(set.count(st-1) == 0){
                int len = 1 ;
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