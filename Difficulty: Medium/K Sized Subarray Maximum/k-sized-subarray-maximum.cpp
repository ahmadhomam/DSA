class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int> q ;
        int n = arr.size() ;
        
        int i=0 ;
        int j =0 ;
        
        vector<int> ans ;
        
        while(j<n){
            while(!q.empty() && arr[j] > arr[q.back()])
            q.pop_back() ;
            
            q.push_back(j) ;
            
            if(j-i+1 < k)
            j++ ;
            
            
            else if(j-i+1 == k) {
                ans.push_back(arr[q.front()]) ;
                
                if(!q.empty() && i == q.front()){
                q.pop_front() ;
                
                }
                
                i++ ;
                j++ ;
            }
        }
        return ans ;
    }
};