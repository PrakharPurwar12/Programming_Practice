#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }
        
        long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(max_val + 1, vector<long long>(max_val + 1, 0));
        dp[0][0] = 1;
        
        for (int x : nums) {
            vector<vector<long long>> next_dp = dp;
            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0) continue;
                    
                    int n1 = (g1 == 0) ? x : std::gcd(g1, x);
                    next_dp[n1][g2] = (next_dp[n1][g2] + dp[g1][g2]) % MOD;
                    
                    int n2 = (g2 == 0) ? x : std::gcd(g2, x);
                    next_dp[g1][n2] = (next_dp[g1][n2] + dp[g1][g2]) % MOD;
                }
            }
            dp = move(next_dp);
        }
        
        long long ans = 0;
        for (int g = 1; g <= max_val; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }
        
        return ans;
    }
};