class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // first window
        int sum = 0 ;
        for(int i=0;i<k;i++){
            sum += nums[i] ;
        }

        double avg = 0 ;
        avg = (double)sum/k ;

        int j = k ;
        int i =0 ;
        while(j<nums.size() && i<j){
            sum += nums[j] ;
            sum -= nums[i] ;
            avg = max(avg,(double)sum/k) ;
            j++ ;
            i++ ;
        }
        return avg ;
    }
};