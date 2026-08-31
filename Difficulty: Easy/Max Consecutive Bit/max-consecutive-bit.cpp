class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        int n = arr.size() ;
        int maxsize =INT_MIN ;
        
        int i=0;
        int j=0 ;
        int size = 0 ;
        
        
        while(j<n){
            if(arr[i] == arr[j]){
                maxsize = max(maxsize,j-i+1) ;
            }
            else{
                i=j ;
            }
            j++ ;
        }
        return maxsize ;
    }
};