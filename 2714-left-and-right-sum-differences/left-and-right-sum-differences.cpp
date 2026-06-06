class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        int left = 0;
        vector<int> answer(n);
        for(int i=0; i<n; i++){
            int right = sum - left - nums[i];

            answer[i] = abs(left-right);
            left += nums[i];
        }
        return answer;
    }
};