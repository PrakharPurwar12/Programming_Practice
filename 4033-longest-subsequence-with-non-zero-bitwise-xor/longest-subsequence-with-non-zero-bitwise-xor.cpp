class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool allZero = true;

        for (int x : nums) {
            totalXor ^= x;
            if (x != 0) {
                allZero = false;
            }
        }

        if (allZero) {
            return 0;
        }

        if (totalXor != 0) {
            return nums.size();
        }

        return nums.size() - 1;
    }
};