class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n == 0) return 0;

        const uint64_t BASE1 = 1315423911ULL;
        const uint64_t MOD1 = 1000000007ULL;
        const uint64_t BASE2 = 2654435761ULL;
        const uint64_t MOD2 = 1000000009ULL;

        vector<uint64_t> p1(n + 1, 1), p2(n + 1, 1);
        vector<uint64_t> h1(n + 1, 0), h2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            uint64_t val = static_cast<uint64_t>(nums[i]);
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
            h1[i + 1] = (h1[i] * BASE1 + val) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + val) % MOD2;
        }

        auto getHash = [&](int l, int r) -> uint64_t {
            uint64_t x1 = (h1[r] + MOD1 - (h1[l] * p1[r - l]) % MOD1) % MOD1;
            uint64_t x2 = (h2[r] + MOD2 - (h2[l] * p2[r - l]) % MOD2) % MOD2;
            return (x1 << 32) | x2;
        };

        auto hasUniqueOfLength = [&](int len) -> bool {
            unordered_map<uint64_t, int> freq;
            freq.reserve(static_cast<size_t>(n - len + 1) * 2);
            for (int i = 0; i + len <= n; ++i) {
                ++freq[getHash(i, i + len)];
            }
            for (const auto& kv : freq) {
                if (kv.second == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUniqueOfLength(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};