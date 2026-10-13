class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            sq[i] = val * val;
        }
        sort(sq.begin(), sq.end());
        long long ans = 0;
        int half = n / 2;
        for (int i = 0; i < half; ++i) {
            ans -= sq[i];
        }
        for (int i = half; i < n; ++i) {
            ans += sq[i];
        }
        return ans;
    }
};