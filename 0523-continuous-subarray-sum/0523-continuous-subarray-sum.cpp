class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //earlier we store the prefix sum with its frequency now we store the reminder with its first occurance.
        // (currsum-prefixsum) % k == 0 => currsum % k - prefixsum % k == 0 ;
        // currsum % k this is what we check at each step == prefixsum % k this what we stored up;

        unordered_map<int,int > map ;
        int n = nums.size() ;
        map[0] = -1  ;// reminder == 0 ka index -1 (suppose whole array is good subarray then i(=4)-(-1) == 5 (size))
        int sum = 0 ;

        for(int i=0;i<n;i++){
            sum += nums[i] ;
            int rem = sum % k ;
            if(map.find(rem) != map.end()){
                if(i-map[rem] >= 2){
                    return true ;
                }
            }
            else{
                map[rem] = i ;
            }
        }
        return false ;
    }
};