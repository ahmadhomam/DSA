class Solution {
public:
    typedef long long ll ;
    long long sumAndMultiply(int n) {
        if(n == 0)
        return 0 ;

        stack<int> s ;
        while (n){
            int digit = n%10 ;

            if(digit != 0)
            s.push(digit) ;

            n /= 10 ;
        }
        ll sum = 0 ;
        ll number = 0 ;
        while(!s.empty()){
            number *= 10 ;
            int top = s.top()  ;
            sum += top ;
            number += top ;
            s.pop() ;
        }
        return sum*number;
    }
};