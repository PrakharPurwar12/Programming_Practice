class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                string sub = s.substr(i, j - i + 1);
                int len = sub.length();
                int min_changes_sub = len;
                
                for (int d = 1; d < len; ++d) {
                    if (len % d == 0) {
                        int changes = 0;
                        for (int g = 0; g < d; ++g) {
                            string group = "";
                            for (int idx = g; idx < len; idx += d) {
                                group += sub[idx];
                            }
                            int gl = group.length();
                            for (int l = 0, r = gl - 1; l < r; ++l, --r) {
                                if (group[l] != group[r]) {
                                    changes++;
                                }
                            }
                        }
                        min_changes_sub = min(min_changes_sub, changes);
                    }
                }
                cost[i][j] = min_changes_sub;
            }
        }
        
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 1e9));
        dp[0][0] = 0;
        
        for (int parts = 1; parts <= k; ++parts) {
            for (int i = 1; i <= n; ++i) {
                for (int j = parts * 2 - 2; j < i - 1; ++j) {
                    if (dp[parts - 1][j] != 1e9) {
                        dp[parts][i] = min(dp[parts][i], dp[parts - 1][j] + cost[j][i - 1]);
                    }
                }
            }
        }
        
        return dp[k][n];
    }
};