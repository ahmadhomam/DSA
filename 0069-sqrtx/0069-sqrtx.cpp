class Solution {
public:
    int mySqrt(int x) {
        int i =1 ;
        int j = x/2 ;
        int ans = 1   ;
        int mid = i + (j-i)/2 ;

        if(x== 0 || x == 1)
        return x ;

        while(i<=j){
            if((long)mid*mid > (long) x)
                j = mid-1 ;
            
            else if(mid*mid == x)
                return mid  ;
            
            else{
                ans = mid ;
                i = mid+1 ;
            }
            mid = i + (j-i)/2 ;
        }
        return ans ;
    }
};