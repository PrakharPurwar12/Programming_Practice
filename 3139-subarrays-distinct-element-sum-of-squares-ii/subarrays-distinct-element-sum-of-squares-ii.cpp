class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> cnt(n + 1), tot(n + 1);
        unordered_map<int, int> last;
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            int p = last.count(nums[r]) ? last[nums[r]] : -1;
            long long c = 0, s = 0;
            for (int i = n - p - 1; i > 0; i -= i & -i)
                c = (c + cnt[i]) % MOD, s = (s + tot[i]) % MOD;
            
            long long term1 = (1LL * (r - p) * (r - p)) % MOD;
            long long term2 = (2 * (s - 1LL * p * c % MOD)) % MOD;
            long long gain = (term1 - term2 + MOD) % MOD;
            
            ans = (ans + (1LL * (n - r) * gain) % MOD) % MOD;
            
            for (int i = n - p; i <= n; i += i & -i) {
                cnt[i] = (cnt[i] + 1) % MOD;
                tot[i] = (tot[i] + (p == -1 ? 0 : p)) % MOD;
            }
            last[nums[r]] = r;
        }
        return ans;
    }
};