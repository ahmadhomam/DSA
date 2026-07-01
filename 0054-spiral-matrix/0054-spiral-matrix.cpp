class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        
        int startrow = 0, endrow = m - 1;
        int startcol = 0, endcol = n - 1;
        
        while (startrow <= endrow && startcol <= endcol) {
            // 1. Move Right
            for (int j = startcol; j <= endcol; j++) {
                ans.push_back(matrix[startrow][j]);
            }
            startrow++; // Shrink top boundary
            
            // 2. Move Down
            for (int i = startrow; i <= endrow; i++) {
                ans.push_back(matrix[i][endcol]);
            }
            endcol--; // Shrink right boundary
            
            // 3. Move Left (Must verify row still exists)
            if (startrow <= endrow) {
                for (int j = endcol; j >= startcol; j--) {
                    ans.push_back(matrix[endrow][j]);
                }
                endrow--; // Shrink bottom boundary
            }
            
            // 4. Move Up (Must verify column still exists)
            if (startcol <= endcol) {
                for (int i = endrow; i >= startrow; i--) {
                    ans.push_back(matrix[i][startcol]);
                }
                startcol++; // Shrink left boundary
            }
        }
        return ans;
    }
};
