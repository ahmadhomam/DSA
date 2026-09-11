class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        int cnt ;
        vector<int> letter(26,0) ;
        vector<int> window(26,0); 
        
        for(auto ch:pat){
            letter[ch-'a']++ ;
        }
        
        int i=0;
        int j=0 ;
        while(j< txt.size()){
            window[txt[j]-'a']++ ;
            
            if(j-i+1 < pat.size())
            j++ ;
            
            else if(j-i+1 == pat.size()){
                if(window == letter){
                    cnt++ ;
                }
                
                window[txt[i]-'a']-- ;
                i++ ;
                j++ ;
            }
        }
        return cnt ;
    }
};