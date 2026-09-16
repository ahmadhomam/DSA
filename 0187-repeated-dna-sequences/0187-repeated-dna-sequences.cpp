class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans ;
        int n = s.size() ;
        unordered_set<string> str ;
        unordered_set<string> added;
        string temp = "";

        int i=0 ;
        int j =0 ;
        while(j<n){
            temp.push_back(s[j]) ;

            if(j-i+1 < 10)
            j++ ;

            else if(j-i+1 == 10){
                if(str.find(temp) == str.end())
                str.insert(temp) ;
                else if (added.find(temp) == added.end()) {
                ans.push_back(temp);
                added.insert(temp); // mark as added so it isn't pushed twice
            }

                temp.erase(0,1) ;
                i++ ;
                j++ ;
            }
        }
        return ans ;
    }
};