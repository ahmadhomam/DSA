class Solution {
public:
    bool isfeasible(vector<int>& bloomDay, int m, int k,int mid){
        int streak =0 ;
        long long boke =0 ;
        int j=0 ;
        while(j<bloomDay.size()){
            if(bloomDay[j] <= mid){
                if(++streak == k){
                    boke++ ;
                    streak = 0 ;
                }
            }
            else{
                streak = 0 ;
            }
            j++ ;
        }
        return boke >= m ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //monotonicity dikh rhi hai: 
        int n = bloomDay.size() ;
        int low = *min_element(bloomDay.begin(),bloomDay.end()) ;
        int high = *max_element(bloomDay.begin(),bloomDay.end()) ;

        int mid  ;
        int ans =-1 ;

        if((long long)m*k > n)
        return -1 ;

        while(low <= high){
            mid = low + (high-low)/2 ;
            if(isfeasible(bloomDay,m,k,mid)){
                ans = mid ;
                high = mid-1 ;
            }
            else 
            low = mid +1 ;
        }
        return ans ;
    }
};