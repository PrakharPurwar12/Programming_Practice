class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));
        
        dp[0][0].insert(grid[0][0]);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int val : dp[i][j]) {
                    if (i + 1 < m) {
                        dp[i + 1][j].insert(val ^ grid[i + 1][j]);
                    }
                    if (j + 1 < n) {
                        dp[i][j + 1].insert(val ^ grid[i][j + 1]);
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        for (int val : dp[m - 1][n - 1]) {
            ans = min(ans, val);
        }
        
        return ans;
    }
};