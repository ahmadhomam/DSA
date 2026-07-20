class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size() ;

        int i=0,j=0 ;
        int maxsize = 0 ;
        int size =0  ;
        unordered_map<char,int> map ;
        
        while(j<n){
            if(map[s[j]]){
                while(map[s[j]] != 0){
                    map[s[i]]-- ;
                    i++ ;
                }
            }
            maxsize = max(maxsize,j-i+1) ;
            map[s[j]]++ ;
            j++ ;

        }
        return maxsize ;
    }
};