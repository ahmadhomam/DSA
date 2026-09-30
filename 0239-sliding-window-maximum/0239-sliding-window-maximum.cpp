class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() ;
        deque<int> q ;
        vector<int> ans ;

        int i =0 ;
        int j=0 ;
        while(j< n) {
            //calculations
            while(!q.empty() && nums[q.back()] < nums[j]){
                    q.pop_back() ;
                }
            q.push_back(j) ;

            //if window less than than k ;
            if(j-i+1<k)
            j++ ;

            // if hit the window size ;
            else if(j-i+1 == k){
                if(q.empty())
                ans.push_back(-1) ;

                else{
                    ans.push_back(nums[q.front()]) ;
                }

                //left se remove 
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