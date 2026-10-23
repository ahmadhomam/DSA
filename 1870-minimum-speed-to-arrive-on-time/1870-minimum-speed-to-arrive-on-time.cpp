class Solution {
public:
    bool isfeasible(vector<int>& dist, double hour,int k){
        double currtime = 0 ;
        for(int i=0;i<dist.size();i++){
            double time = dist[i]/double(k) ;
            if(i != dist.size()-1)
            time= ceil(time) ;

            currtime += time ;

            if(currtime > hour) return false ;
        }
        return true ;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1 ;
        int high = 10000000;
        int mid ;

        int ans = -1 ;
        if(hour <= dist.size()-1)
        return -1 ;

        while(low <= high){
            mid = low + (high-low)/2  ;

            if(isfeasible(dist,hour,mid)){
                ans = mid ;
                high  = mid-1  ;
            }
            else
                low = mid+1 ;
        }
        return ans ;
    }
};