class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
        return 0 ;
        
        sort(nums.begin(), nums.end()); 

        // Track last smaller element
        int lastSmaller = INT_MIN; 
        // Count current sequence length
        int cnt = 0; 
        // Track longest sequence length
        int longest = 1; 

        for (int i = 0; i < nums.size(); i++) {
            // If consecutive number exists
            if (nums[i] - 1 == lastSmaller) {
                // Increment sequence count
                cnt += 1; 
                // Update last smaller element
                lastSmaller = nums[i]; 
            } 
            // If consecutive number doesn't exits
            else if (nums[i] != lastSmaller) {
                // Reset count for new sequence
                cnt = 1; 
                // Update last smaller element
                lastSmaller = nums[i]; 
            }
            // Update longest if needed
            longest = max(longest, cnt); 
        }
        return longest;
    }
};