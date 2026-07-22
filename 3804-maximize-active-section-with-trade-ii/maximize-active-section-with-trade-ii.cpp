#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }

        struct Segment {
            int type;
            int L, R;
            int len;
        };

        vector<Segment> segs;
        if (s[0] == '1') {
            segs.push_back({0, 0, -1, 0});
        }

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            segs.push_back({s[i] - '0', i, j - 1, j - i});
            i = j;
        }

        if (segs.back().type == 1) {
            segs.push_back({0, n, n - 1, 0});
        }

        int m = segs.size();
        int num_ones_segs = m / 2;

        vector<int> V(num_ones_segs);
        vector<int> ones_L(num_ones_segs), ones_R(num_ones_segs);
        vector<int> zero_L(num_ones_segs), zero_R(num_ones_segs);

        for (int k = 0; k < num_ones_segs; k++) {
            int idx = 2 * k + 1;
            V[k] = segs[idx - 1].len + segs[idx + 1].len;
            ones_L[k] = segs[idx].L;
            ones_R[k] = segs[idx].R;
            zero_L[k] = segs[idx - 1].L;
            zero_R[k] = segs[idx + 1].R;
        }

        int K = num_ones_segs;
        int LOG = 0;
        while ((1 << LOG) <= K) LOG++;
        if (LOG == 0) LOG = 1;

        vector<vector<int>> st(LOG, vector<int>(K, 0));
        for (int i = 0; i < K; i++) st[0][i] = V[i];

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= K; i++) {
                st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }

        auto query_st = [&](int L, int R) {
            if (L > R) return 0;
            int j = 32 - __builtin_clz(R - L + 1) - 1;
            return max(st[j][L], st[j][R - (1 << j) + 1]);
        };

        auto get_gain = [&](int k, int l, int r) {
            int idx = 2 * k + 1;
            int left_len = segs[idx - 1].R - max(segs[idx - 1].L, l) + 1;
            int right_len = min(segs[idx + 1].R, r) - segs[idx + 1].L + 1;
            return left_len + right_len;
        };

        vector<int> ans(queries.size());

        for (size_t q = 0; q < queries.size(); q++) {
            int l = queries[q][0];
            int r = queries[q][1];

            int first_k = lower_bound(ones_L.begin(), ones_L.end(), l + 1) - ones_L.begin();
            int last_k = upper_bound(ones_R.begin(), ones_R.end(), r - 1) - ones_R.begin() - 1;

            if (first_k > last_k) {
                ans[q] = total_ones;
                continue;
            }

            int max_gain = 0;
            max_gain = max(max_gain, get_gain(first_k, l, r));
            max_gain = max(max_gain, get_gain(last_k, l, r));

            int fk_full = lower_bound(zero_L.begin(), zero_L.end(), l) - zero_L.begin();
            int lk_full = upper_bound(zero_R.begin(), zero_R.end(), r) - zero_R.begin() - 1;

            fk_full = max(fk_full, first_k);
            lk_full = min(lk_full, last_k);

            if (fk_full <= lk_full) {
                max_gain = max(max_gain, query_st(fk_full, lk_full));
            }

            ans[q] = total_ones + max_gain;
        }

        return ans;
    }
};