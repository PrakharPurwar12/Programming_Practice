class Solution {
    multiset<long long> low, high;
    long long sum_low = 0, sum_high = 0;
    int target_low_size;

    void add(long long val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            sum_low += val;
        } else {
            high.insert(val);
            sum_high += val;
        }
        rebalance();
    }

    void remove(long long val) {
        auto it = low.find(val);
        if (it != low.end()) {
            sum_low -= val;
            low.erase(it);
        } else {
            it = high.find(val);
            sum_high -= val;
            high.erase(it);
        }
        rebalance();
    }

    void rebalance() {
        while ((int)low.size() < target_low_size && !high.empty()) {
            auto it = high.begin();
            long long val = *it;
            sum_high -= val;
            high.erase(it);
            low.insert(val);
            sum_low += val;
        }
        while ((int)low.size() > target_low_size) {
            auto it = prev(low.end());
            long long val = *it;
            sum_low -= val;
            low.erase(it);
            high.insert(val);
            sum_high += val;
        }
    }

    long long getCost() {
        long long median = *low.rbegin();
        long long cost_low = median * low.size() - sum_low;
        long long cost_high = sum_high - median * high.size();
        return cost_low + cost_high;
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        target_low_size = (x + 1) / 2;

        low.clear();
        high.clear();
        sum_low = 0;
        sum_high = 0;

        vector<long long> cost(n, 0);

        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                cost[i] = getCost();
            }
        }

        const long long INF = 1e18;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));

        for (int i = 0; i <= n; ++i) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; ++j) {
            for (int i = 1; i <= n; ++i) {
                dp[j][i] = dp[j][i - 1];
                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - 1]);
                }
            }
        }

        return dp[k][n];
    }
};