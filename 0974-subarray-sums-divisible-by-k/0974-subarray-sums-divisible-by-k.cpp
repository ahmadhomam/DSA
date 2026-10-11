class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int> map ; // store the reminder with their frequency ;
        // subarray % k == 0 
        // subarray = (currsum - prefix)% k == 0 ;
        // currsum % k == prefix % k ;
        // agr currsum ka reminder = hai prefix sum ke reminder ke then wo subarray valid hai

        int sum = 0 ;
        map[0] = 1 ; //reminder=0 hai ek baar 
        int count = 0 ; //no of subarray

        for(int i=0;i<n;i++){
            sum += nums[i] ; 
            int rem = (sum % k) ;
            if(rem < 0)
            rem += k ;
            if(map.find(rem) != map.end()){
                count += map[rem] ;
            }
            map[rem]++ ;
        }

        return count ;
    }
};