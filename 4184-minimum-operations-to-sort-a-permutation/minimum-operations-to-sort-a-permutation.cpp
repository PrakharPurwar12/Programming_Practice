class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int zero = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }

        auto check = [&](int step) {
            for (int i = 0; i < n; ++i) {
                int expected = i;
                int actual = nums[(zero + (long long)i * step % n + n) % n];
                if (actual != expected) return false;
            }
            return true;
        };

        int ans = 1e9;

        if (check(1)) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        if (check(-1)) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans > 2 * n ? -1 : ans;
    }
};