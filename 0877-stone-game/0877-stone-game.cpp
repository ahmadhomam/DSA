class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // dp[i][j] stores the max relative score advantage for the subarray piles[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: Only one pile left, the player must take it
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // Fill the DP table for subarrays of increasing lengths
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                // Maximize picking from left or right, minus the opponent's subsequent advantage
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }

        // If the margin for the full array is greater than 0, Alice wins
        return dp[0][n - 1] > 0;
    }
};
