class Solution {
public:
    typedef long long ll ;
    int maximumLength(vector<int>& nums) {
        int n = nums.size() ;
        int maxsize = 1 ;
        unordered_map<ll,int> map ;

        for(ll num : nums){
            map[num]++ ;
        }

        if(map[1]%2 == 0)
        maxsize = map[1]-1 ;
        else
        maxsize = map[1] ;

        for(auto [num,_] : map){
            int size = 0 ;
            ll curr = num ;
            
            if (curr == 1)
            continue ;

            while(map.count(curr) && map[curr]  > 1){
                size += 2 ;
                curr = curr*curr ;
            }

            if(map.count(curr) == 1)
            size += 1 ;
            
            else
            size -=1 ;

            maxsize = max(size,maxsize) ;
            
        }
        return maxsize ;
    }
};