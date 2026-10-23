class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool first = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                if(first){
                    ans = nums[i];
                    first = false;
                }else{
                    ans = ans & nums[i];
                }
            }
        }
        return ans;
    }
};