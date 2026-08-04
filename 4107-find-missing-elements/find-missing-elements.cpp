class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> present(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());

        vector<int> ans;
        for (int i = min_val + 1; i < max_val; ++i) {
            if (present.find(i) == present.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};