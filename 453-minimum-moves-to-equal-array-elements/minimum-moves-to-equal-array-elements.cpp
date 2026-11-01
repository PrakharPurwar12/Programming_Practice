class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, minVal = nums[0];
        for (int x : nums) {
            sum += x;
            if (x < minVal) {
                minVal = x;
            }
        }
        return sum - minVal * nums.size();
    }
};