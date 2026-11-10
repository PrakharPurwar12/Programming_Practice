class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == 1e18) continue;
            for (int step = 1; step <= 3 && i + step <= n; ++step) {
                int j = i + step;
                long long cost = dp[i] + costs[j - 1] + 1LL * (step) * (step);
                if (cost < dp[j]) {
                    dp[j] = cost;
                }
            }
        }
        return dp[n];
    }
};