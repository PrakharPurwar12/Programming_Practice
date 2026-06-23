class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double max_sum = 0;
        if (n < k) {
            return -1;
        }

        for(int i = 0;i<k; i++){
            max_sum+=nums[i];
        }
        double window_sum = max_sum;
        for (int i = k; i < n; i++) {
            window_sum += nums[i] - nums[i - k];
            max_sum = max(max_sum, window_sum);
        }
        return max_sum/k;
    }
};