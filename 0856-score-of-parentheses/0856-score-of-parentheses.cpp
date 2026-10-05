class Solution {
public:
    int scoreOfParentheses(string s) {
        int count = 0 ;
        int level = 0 ;

        for (int i=0 ;i<s.size() ;i++){
            if(s[i] == '('){
                level++ ;
            }
            else{
                level-- ;
                // checking if the pair "()" exist
                if(s[i-1] == '('){
                    count += 1<<level; 
                }
            }
        }
        return count ;
    }
};