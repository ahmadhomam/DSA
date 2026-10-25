class Solution {
public:
    bool isfeasible(vector<int> &position,int k , int mid){
        int cows = 1 ;
        int lastposition = position[0] ;
        
        for(int i=0;i<position.size();i++){
            if(position[i]-lastposition >= mid){
                cows++ ;
                lastposition = position[i] ;
            }
            
            if(cows == k)
            return true ;
        }
        return false ;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size() ;
        sort(position.begin(),position.end()) ;
        int low = 1;
        int high = position[n-1]-position[0] ;
        
        int mid ;
        int ans = -1 ;
        
        if(m >n)
        return -1 ;
        
        while(low <= high){
            mid = low + (high-low)/ 2;
            
            if(isfeasible(position,m,mid)){
                ans = mid ;
                low = mid+1 ;
            }
            
            else
            high = mid-1 ;
        }
        return ans ;
    }
};