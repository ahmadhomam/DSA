class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end()) ;
        
        int i=0 ;
        int n = a.size() ;
        int mini= INT_MAX ;
        
        while(i+m-1 < n){
            mini = min(mini,a[i+m-1]-a[i]) ;
            i++ ;
        }
        
        return mini ;
    }
};