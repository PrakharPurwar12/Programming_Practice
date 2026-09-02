class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size()+1;
        int sum1 = 0;
        for(int i=0; i<n;i++){
            sum1+=i;
        }
        int sum2 = 0;
        for(int i=0; i<nums.size(); i++){
            sum2+=nums[i];
        }
        int sum = sum1 - sum2;
        return sum;
    }
};