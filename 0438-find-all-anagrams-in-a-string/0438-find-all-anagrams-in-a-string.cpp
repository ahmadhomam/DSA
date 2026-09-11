class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> letters(26,0) ;
        vector<int> count(26,0) ;
        
        vector<int> ans ;

        for (auto ch : p)
        letters[ch-'a']++ ;


        int j=0 ;
        int i=0 ;
        while(j< s.size()) {
            count[s[j]-'a']++ ;
            
            if(j-i+1 < p.size())
            j++ ;

            else if(j-i+1 == p.size()){
                if(count == letters)
                ans.push_back(i) ;

                count[s[i]- 'a']-- ;
                i++ ;
                j++ ;
            }
        }
        return ans ;
    }
};