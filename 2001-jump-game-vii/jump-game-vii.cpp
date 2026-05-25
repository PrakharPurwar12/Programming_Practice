class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] == '1') return false;

        vector<bool> dp(n, false);
        dp[0] = true; 
        int reachable_count = 0;

        for (int i = 1; i < n; i++) {
            if (i >= minJump) {
                if (dp[i - minJump]) {
                    reachable_count++;
                }
            }

            if (i > maxJump) {
                if (dp[i - maxJump - 1]) {
                    reachable_count--;
                }
            }

            if (s[i] == '0' && reachable_count > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};