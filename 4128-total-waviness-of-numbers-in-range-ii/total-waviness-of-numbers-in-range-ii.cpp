class Solution {
public:
    struct Node {
        long long ways;
        long long sum;
    };

    string s;
    Node dp[17][2][11][11];
    bool vis[17][2][11][11];

    Node dfs(int pos, bool started, int prev1, int prev2, bool tight) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][started][prev1][prev2]) {
            return dp[pos][started][prev1][prev2];
        }

        int limit = tight ? s[pos] - '0' : 9;

        long long totalWays = 0;
        long long totalSum = 0;

        for (int d = 0; d <= limit; d++) {

            bool nextTight = tight && (d == limit);

            if (!started && d == 0) {

                Node nxt = dfs(pos + 1, false, 10, 10, nextTight);

                totalWays += nxt.ways;
                totalSum += nxt.sum;
            }
            else {

                int add = 0;

                if (started && prev2 != 10) {

                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d)) {
                        add = 1;
                    }
                }

                int newPrev2, newPrev1;

                if (!started) {
                    newPrev2 = 10;
                    newPrev1 = d;
                } else {
                    newPrev2 = prev1;
                    newPrev1 = d;
                }

                Node nxt = dfs(
                    pos + 1,
                    true,
                    newPrev1,
                    newPrev2,
                    nextTight
                );

                totalWays += nxt.ways;
                totalSum += nxt.sum + 1LL * add * nxt.ways;
            }
        }

        Node ans = {totalWays, totalSum};

        if (!tight) {
            vis[pos][started][prev1][prev2] = true;
            dp[pos][started][prev1][prev2] = ans;
        }

        return ans;
    }

    long long solve(long long n) {

        if (n <= 0) return 0;

        s = to_string(n);

        memset(vis, 0, sizeof(vis));

        return dfs(0, false, 10, 10, true).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};