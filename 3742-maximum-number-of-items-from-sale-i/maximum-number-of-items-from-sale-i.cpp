class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int maxF = 1;
        for (const auto& it : items) {
            maxF = max(maxF, it[0]);
        }

        vector<int> freq(maxF + 1, 0);
        for (const auto& it : items) {
            freq[it[0]]++;
        }

        vector<int> multCount(maxF + 1, 0);
        for (int f = 1; f <= maxF; ++f) {
            if (freq[f] == 0) continue;
            for (int m = f; m <= maxF; m += f) {
                multCount[f] += freq[m];
            }
        }

        const int NEG_INF = -1e9;
        vector<int> dp(budget + 1, NEG_INF);
        dp[budget] = 0;

        for (int i = 0; i < n; ++i) {
            int f = items[i][0];
            int price = items[i][1];
            int gain = multCount[f] - 1;

            vector<int> firstBuy(budget + 1, NEG_INF);
            for (int b = budget; b >= price; --b) {
                if (dp[b] != NEG_INF) {
                    int nb = b - price;
                    firstBuy[nb] = max(firstBuy[nb], dp[b] + 1 + gain);
                }
            }

            for (int b = budget - price; b >= 0; --b) {
                if (firstBuy[b + price] != NEG_INF) {
                    firstBuy[b] = max(firstBuy[b], firstBuy[b + price] + 1);
                }
            }

            for (int b = 0; b <= budget; ++b) {
                dp[b] = max(dp[b], firstBuy[b]);
            }
        }

        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            ans = max(ans, dp[b]);
        }
        return ans;
    }
};