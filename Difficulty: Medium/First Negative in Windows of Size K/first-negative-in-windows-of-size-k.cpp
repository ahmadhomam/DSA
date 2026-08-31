class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // code here
        int n = arr.size() ;
        deque<int> l ;
        vector<int> ans ;
        
        int i =0 ;
        int j =0 ;
        
        while(j<n){
            if(arr[j]<0)
            l.push_back(arr[j]) ;
            
            if(j-i+1 <k)
            j++ ;
            
            else if (j-i+1 == k){
                if(l.empty())
                ans.push_back(0) ;
                
                else
                ans.push_back(l.front()) ;
                
                //updating the window
                if(l.front() == arr[i])
                l.pop_front() ;
                
                i++ ;
                j++ ;
            }
        }
        return ans ;
    }
};