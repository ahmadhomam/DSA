# Longest Substring with K Uniques

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a string  **s**  consisting only lowercase alphabets and an integer  **k**. Your task is to find the  **length** of the  **longest substring**  that contains exactly  **k**  distinct characters.

 **Note :**  If no such substring exists, return  **-1**. 

 **Examples:** 

```
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

```

```
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.

```

```
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-20T11:38:04.025Z  

```cpp
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

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)