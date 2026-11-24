class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            int g = 0;
            long long l = 1;
            for (int j = i; j < n; ++j) {
                long long x = nums[j];
                if (prod > LLONG_MAX / x) {
                    break;
                }
                prod *= x;
                g = (g == 0) ? nums[j] : gcd(g, nums[j]);
                l = (l / gcd(l, x)) * x;
                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};