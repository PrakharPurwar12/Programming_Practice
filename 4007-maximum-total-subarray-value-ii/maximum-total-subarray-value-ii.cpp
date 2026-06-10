#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> st_max;
    vector<vector<int>> st_min;
    vector<int> lg;

    void buildSparseTable(const vector<int>& nums, int n) {
        int max_log = log2(n) + 1;
        st_max.assign(n, vector<int>(max_log, 0));
        st_min.assign(n, vector<int>(max_log, 0));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        for (int i = 0; i < n; i++) {
            st_max[i][0] = nums[i];
            st_min[i][0] = nums[i];
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    long long queryValue(int l, int r) {
        int j = lg[r - l + 1];
        int mx = max(st_max[l][j], st_max[r - (1 << j) + 1][j]);
        int mn = min(st_min[l][j], st_min[r - (1 << j) + 1][j]);
        return (long long)mx - mn;
    }

    struct SubarrayState {
        long long value;
        int l;
        int r;

        bool operator<(const SubarrayState& other) const {
            return value < other.value;
        }
    };

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        buildSparseTable(nums, n);

        priority_queue<SubarrayState> pq;

        for (int i = 0; i < n; i++) {
            long long val = queryValue(i, n - 1);
            pq.push({val, i, n - 1});
        }

        long long total_max_value = 0;

        for (int step = 0; step < k; step++) {
            auto current = pq.top();
            pq.pop();

            total_max_value += current.value;

            if (current.r > current.l) {
                long long next_val = queryValue(current.l, current.r - 1);
                pq.push({next_val, current.l, current.r - 1});
            }
        }

        return total_max_value;
    }
};