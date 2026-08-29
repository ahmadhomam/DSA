class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int i=0 ;
        int j = arr.size()-1 ;
        int maxarea = 0 ;
        
        while(i<j){
            int h = min(arr[i],arr[j]);
            int l= j-i ;
            
            maxarea = max(maxarea,l*h) ;
            
            if(arr[i]<arr[j])
            i++ ;
            else
            j-- ;
        }
        return maxarea ;
    }
};