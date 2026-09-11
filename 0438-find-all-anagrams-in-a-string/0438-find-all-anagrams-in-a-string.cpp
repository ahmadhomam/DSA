class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans ;
        unordered_map<char,int> map ;

        for(auto m : p)
        map[m]++ ;
    

        int count = map.size() ;
        int j=0 ;
        int i =0 ;

        while(j < s.size()){
            if(map.find(s[j]) != map.end()){
            map[s[j]]--;

            if(map[s[j]] == 0) 
            count-- ;
            }

            if(j-i+1 < p.size())
            j++ ;

            else if(j-i+1 == p.size()){
                if(count == 0)
                ans.push_back(i) ; 

                // restoring the map
                if(map.find(s[i]) != map.end()){
                // restoring the count 
                if(map[s[i]] == 0){
                    count++ ;
                }
                map[s[i]]++ ;
                }
                i++ ;
                j++ ;
            }
        }
    return ans ;
    }
};