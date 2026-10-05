class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size() ;
        int i=0 ;
        int j=0 ;
        int count = 0 ;
        unordered_map<int,int> map ;
        while(j<n){
            //calculations
            map[fruits[j]]++ ;

            //if invalid
            while(map.size() >2){
                map[fruits[i]]-- ;
                if(map[fruits[i]] == 0)
                map.erase(fruits[i]) ;

                i++ ;
            }

            //valid
            count = max(count,j-i+1) ;
            j++ ;
        }
        return count ;
    }
};