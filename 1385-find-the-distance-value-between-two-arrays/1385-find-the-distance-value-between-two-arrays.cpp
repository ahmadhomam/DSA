class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int validCount = 0;
        
        for (int i = 0; i < arr1.size(); i++) {
            bool isValid = true;
            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    isValid = false; // Found an element within distance d, so arr1[i] is disqualified
                    break;           // No need to check remaining elements in arr2
                }
            }
            if (isValid) {
                validCount++;        // Safe from all elements in arr2
            }
        }
        
        return validCount;
    }
};