class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set ;
        int n = s.size() ;

        int i=0 ;
        int j =0 ;
        int maxsize = 0;
        while(j<n){
            //calculations :
            // size badhana hai (kuch mat kro)
            

            while(set.find(s[j]) != set.end()){
                set.erase(s[i]) ;
                i++ ;
            }

            maxsize = max(maxsize,j-i+1) ;
            set.insert(s[j]) ;
            j++ ;

        }
        return maxsize ;
    }
};