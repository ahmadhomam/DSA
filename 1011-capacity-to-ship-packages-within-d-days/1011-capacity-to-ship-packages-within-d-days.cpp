class Solution {
public:
    bool isfeasible(vector<int>& weights, int days, int k){
        int count = 1 ;
        int onedaysum = 0 ;
        for(int i=0;i<weights.size();i++){
            if(onedaysum + weights[i] > k){
                count++ ;
                onedaysum = 0 ;
            }
            onedaysum += weights[i] ;
        }

        return (count <= days) ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // here we need to minimize the weight to ship in [days] days.
        // its binary search on answer, we have to apply the binary search on possible range of answer
        int low = *max_element(weights.begin(),weights.end()) ;
        int high = accumulate(weights.begin(),weights.end(),0) ;

        int mid ;
        int ans =-1 ;
        if(days == 1)
        return high ;

        while(low <= high){
            mid = low + (high-low)/2 ;

            if(isfeasible(weights,days,mid)){
                ans = mid ;
                high = mid-1 ;
            }
            else{
                low = mid+1 ;
            }
        }
        return ans  ;
    }
};