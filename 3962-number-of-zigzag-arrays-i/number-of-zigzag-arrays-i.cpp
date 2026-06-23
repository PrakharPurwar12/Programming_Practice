class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return r - l + 1;
        
        long long MOD = 1e9 + 7;
        int m = r - l + 1;
        
        vector<vector<long long>> dp(2, vector<long long>(m, 0));
        vector<vector<long long>> next_dp(2, vector<long long>(m, 0));
        vector<long long> pref1(m, 0);
        vector<long long> suff0(m, 0);
        
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < m; ++y) {
                if (x < y) {
                    dp[0][y] = (dp[0][y] + 1) % MOD;
                } else if (x > y) {
                    dp[1][y] = (dp[1][y] + 1) % MOD;
                }
            }
        }
        
        for (int i = 3; i <= n; ++i) {
            next_dp[0].assign(m, 0);
            next_dp[1].assign(m, 0);
            
            pref1[0] = dp[1][0];
            for (int x = 1; x < m; ++x) {
                pref1[x] = (pref1[x - 1] + dp[1][x]) % MOD;
            }
            
            suff0[m - 1] = dp[0][m - 1];
            for (int x = m - 2; x >= 0; --x) {
                suff0[x] = (suff0[x + 1] + dp[0][x]) % MOD;
            }
            
            for (int y = 0; y < m; ++y) {
                if (y > 0) {
                    next_dp[0][y] = pref1[y - 1];
                }
                if (y < m - 1) {
                    next_dp[1][y] = suff0[y + 1];
                }
            }
            
            dp = next_dp;
        }
        
        long long ans = 0;
        for (int x = 0; x < m; ++x) {
            ans = (ans + dp[0][x] + dp[1][x]) % MOD;
        }
        
        return ans;
    }
};