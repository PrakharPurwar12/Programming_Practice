class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> desc(n);
        for (int i = 1; i < n; i++) desc[i] = desc[i - 1] + (nums[i - 1] > nums[i]);
        
        vector<int> premax(n), sufmin(n);
        inclusive_scan(nums.begin(), nums.end(), premax.begin(), [](int a, int b) { return max(a, b); });
        inclusive_scan(nums.rbegin(), nums.rend(), sufmin.rbegin(), [](int a, int b) { return min(a, b); });
        
        vector<bool> cut(n, true);
        for (int m = 1; m < n; m++) cut[m] = premax[m - 1] <= sufmin[m];

        auto rotatable = [&](int l, int r) {
            return desc[r] - desc[l] + (nums[r] > nums[l]) <= 1;
        };

        vector<int> drops;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) drops.push_back(i);
        }

        auto sortable = [&](int k) {
            if (drops.size() > n / k) return false;
            int prev_block = -1, prev_drop = -1;
            for (int j : drops) {
                int block = j / k;
                int start = j - (j % k);
                int end = start + k - 1;
                
                if ((j % k == k - 1) || (block == prev_block) || (nums[end] > nums[start]) ||
                    (start && (prev_block == block - 1 ? nums[prev_drop] : nums[start - 1]) > nums[j + 1]) ||
                    (end + 1 < n && nums[j] > nums[end + 1])) {
                    return false;
                }
                prev_block = block;
                prev_drop = j;
            }
            return true;
        };

        int total_sum = 0;
        for (int k = 1; k <= sqrt(n); ++k) {
            if (n % k == 0) {
                if (sortable(k)) total_sum += k;
                int k2 = n / k;
                if (k2 != k && sortable(k2)) total_sum += k2;
            }
        }
        return total_sum;
    }
};