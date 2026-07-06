class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() ;
        int left = n ;
        int maxend = 0 ;
        int count =0 ;

        if(n == 1)
        return 1 ;

        // sort lexicographical for first element but if the first element equal then largerend first ;
        sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]){
                return a[1] > b[1] ;
            }
            return a[0] < b[0] ;
        }) ;

        //the intuition for this type of sorting is simple that the covering element lies first the covered element ;


        for(int j=0;j<n;j++){
            if(intervals[j][1] > maxend){
                count++ ;
                maxend = intervals[j][1] ;
            }
        }
        return count ;
    }
};