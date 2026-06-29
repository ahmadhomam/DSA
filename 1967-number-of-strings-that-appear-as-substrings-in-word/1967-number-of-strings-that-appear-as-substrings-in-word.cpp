class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans =0 ;
        for(string st : patterns){
            if(word.find(st) != string:: npos)
            ans++ ;
        }
        return ans ;
    }
};