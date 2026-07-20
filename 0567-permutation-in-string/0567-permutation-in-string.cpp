class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
        return false ;

        vector<int> s1freq(26,0) ; 
        for(auto ch:s1)
        s1freq[ch-'a']++ ;

        vector<int> s2freq(26,0)  ;
        int i=0,j=0 ;
        while(j<s2.size()){
            s2freq[s2[j]-'a']++ ;

            if(j-i+1 == s1.size()){
                if(s1freq == s2freq) 
                return true ;
            }
            if(j-i+1 >= s1.size()){
                s2freq[s2[i]-'a']-- ;
                i++ ;
            }
            j++  ;
        }
        return false ;
    }
};