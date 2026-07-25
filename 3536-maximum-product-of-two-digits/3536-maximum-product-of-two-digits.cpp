class Solution {
public:
    int maxProduct(int n) {
        int prev = 1;
        vector<int> temp ;
        while(n){
            int digit = n%10 ;
            temp.push_back(digit) ;
            n /= 10 ;
        }

        sort(temp.begin(),temp.end()) ;
        reverse(temp.begin(),temp.end()) ;

        int ans = temp[0]*temp[1] ;
        return ans ;
    }
};