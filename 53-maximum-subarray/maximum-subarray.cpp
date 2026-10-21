class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        int maxEnd = nums[0];
        int overallMax = nums[0];

        for(int i = 1; i<n; i++){
            maxEnd = max(maxEnd+nums[i],nums[i]);
            overallMax = max(maxEnd, overallMax);
        }
        return overallMax;
    }
};