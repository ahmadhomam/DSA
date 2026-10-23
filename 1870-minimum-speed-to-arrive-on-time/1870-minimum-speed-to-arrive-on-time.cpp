class Solution {
public:
    bool isfeasible(vector<int>& dist, double hour,int k){
        int count = 0 ;
        double currtime = 0 ;
        for(int i=0;i<dist.size();i++){
            double time = dist[i]/double(k) ;
            if(i != dist.size()-1)
            time= ceil(time) ;

            currtime += time ;
        }
        return currtime <= hour ;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 0 ;
        int high = 10e7;
        int mid ;

        int ans = -1 ;
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