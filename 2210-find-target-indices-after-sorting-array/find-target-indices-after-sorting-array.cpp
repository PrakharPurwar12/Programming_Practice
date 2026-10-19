class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0, less = 0;
        for (int num : nums) {
            if (num < target) less++;
            if (num == target) count++;
        }
        vector<int> result;
        for (int i = 0; i < count; i++) {
            result.push_back(less + i);
        }
        return result;
    }
};