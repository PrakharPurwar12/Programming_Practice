class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int min_idx = 0;
        int max_idx = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }

        int left = min(min_idx, max_idx);
        int right = max(min_idx, max_idx);

        int remove_front = right + 1;
        int remove_back = n - left;
        int remove_both = (left + 1) + (n - right);

        return min({remove_front, remove_back, remove_both});
    }
};