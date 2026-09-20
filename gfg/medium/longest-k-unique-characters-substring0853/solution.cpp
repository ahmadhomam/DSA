class Solution {
	public:
	int longestKSubstr(string &s, int k) {
		// code here
		int n = s.size() ;
		unordered_map<char, int> freq ;
		int maxsize = -1 ;
		
		int i = 0, j = 0 ;
		
		while (j<n) {
			// calculations
			freq[s[j]]++ ;
			
			// if invalid wala case : longest size nikalna hai
			while (freq.size() > k) {
				freq[s[i]]--;
				
				if (freq[s[i]] == 0) {
					freq.erase(s[i]);
				}
				
				i++;
			}
			
			// found valid
			if (freq.size() == k) {
				maxsize = max(maxsize, j - i + 1) ;
			}
			
			j++ ;
			
		}
		return maxsize ;
		
	}
};
