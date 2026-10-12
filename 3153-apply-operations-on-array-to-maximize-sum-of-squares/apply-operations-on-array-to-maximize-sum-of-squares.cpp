class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit_counts(32, 0);
        for (int x : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((x >> i) & 1) {
                    bit_counts[i]++;
                }
            }
        }
        
        long long ans = 0;
        long long MOD = 1e9 + 7;
        
        for (int step = 0; step < k; ++step) {
            long long curr = 0;
            for (int i = 0; i < 32; ++i) {
                if (bit_counts[i] > 0) {
                    curr |= (1LL << i);
                    bit_counts[i]--;
                }
            }
            ans = (ans + (curr * curr) % MOD) % MOD;
        }
        
        return ans;
    }
};