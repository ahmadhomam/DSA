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
            

            // if invalid => shrink()
            while(set.find(s[j]) != set.end()){
                set.erase(s[i]) ;
                i++ ;
            }

            //if found valid => update the answer
            maxsize = max(maxsize,j-i+1) ;
            set.insert(s[j]) ;
            j++ ;

        }
        return maxsize ;
    }
};