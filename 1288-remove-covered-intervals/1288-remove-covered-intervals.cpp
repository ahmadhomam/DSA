class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() ;
        int left = n ;

        if(n == 1)
        return 1 ;


        sort(intervals.begin(),intervals.end()) ;
        unordered_map<int,bool> map ;

        for(int j=1;j<n;j++){
            int i = 0 ;
            while(i<j){
                if(intervals[j][1] <= intervals[i][1] && map[j] != true){
                left-- ;
                map[j] = true ;
            }
            else{
                if(intervals[j][0] <= intervals[i][0] && map[i] != true)
                left-- ;
                map[i] = true ;
            }
            i++ ;
            }
        }
        return left ;
    }
};