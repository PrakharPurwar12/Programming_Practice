class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;

        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> seen(nums.begin() + i, nums.begin() + i + k);
            for (int val : seen) {
                count[val]++;
            }
        }

        int ans = -1;
        for (const auto& [val, freq] : count) {
            if (freq == 1) {
                ans = max(ans, val);
            }
        }

        return ans;
    }
};