class Solution {
public:
    bool canfinish(vector<int> &piles,int h, int k){
        int hour = 0 ;
        for(auto pile : piles){
            hour += pile/k ;
            if(pile % k)
            hour++ ;

            if(hour > h) 
            return false ;
        }
        return true ;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 ;
        int high = *max_element(piles.begin(),piles.end()) ;

        int mid  ;
        int ans =-1 ;
        while(low <= high){
            mid = low + (high-low)/2 ;

            if(canfinish(piles,h,mid)){
                ans = mid ;
                high = mid-1 ;
            }
            else
            low = mid + 1 ;
        }
        return ans ;
    }
};