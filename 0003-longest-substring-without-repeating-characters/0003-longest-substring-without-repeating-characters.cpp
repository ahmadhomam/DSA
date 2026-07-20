class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size() ;
        int j = 0 ;
        int i =0 ;
        string ans ;
        int maxsize = 0 ;

        string temp = "" ;
        int size = 0 ;
        unordered_map<char,int> map ;

        while(j< n){
            if(!map[s[j]]){
                temp += s[j] ;
                size++ ;
                map[s[j]]++  ;
                j++ ;
            }
            else{
                if(maxsize < size){
                    ans =  temp  ;
                    maxsize = size ;
                }
                while(map[s[j]] != 0){
                    map[s[i]]-- ;
                    size-- ;
                    i++ ;
                }
            }
        }
        return maxsize >= size ? maxsize : size ;
    }
};